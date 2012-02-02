#include "PaletElastiqueHaptique.h"


PaletElastiqueHaptique::PaletElastiqueHaptique(GUITerrain *fenetre, Terrain *terrain) : PaletHaptique(fenetre, terrain)
{
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		ressort = new CImmSpring();
		if (!ressort->InitializeFromProject(*mProjet, "PaletMou", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete ressort;
			ressort = NULL;
		}
		ressort->ChangeDuration(500);
	}
	
	//palet elastique
	terrain->getPalet()->addObserver(fenetre->getGuiPalet());
}


PaletElastiqueHaptique::~PaletElastiqueHaptique()
{
	if (ressort != NULL)
		delete ressort;
	ressort = NULL;
	terrain->getPalet()->deleteObserver(fenetre->getGuiPalet());
}

void PaletElastiqueHaptique::recentrer()
{
}

void PaletElastiqueHaptique::Start()
{
	ressort->Start();
}

void PaletElastiqueHaptique::Stop()
{
	ressort->Stop();
}

void PaletElastiqueHaptique::update(Observable *o, Data *data)
{
	DataCoordonnee *d = dynamic_cast<DataCoordonnee*>(data);
	if (d != NULL)
	{
		//DataCoordonnee *d = (DataCoordonnee*)data;
		long angley = d->vy;
		//this->setCentreRelatif(d->x, d->y);

		//force->ChangeDirection(anglex, angley);
		POINT p;
		p.x = d->x;
		p.y = d->y;

		if (angley < 0)
		{
			ressort->ChangePositiveCoefficientY(8634);
			ressort->ChangeNegativeCoefficientY(-10000);
		}
		else
		{
			ressort->ChangePositiveCoefficientY(-10000);
			ressort->ChangeNegativeCoefficientY(8415);
		}

		ressort->ChangeCenter(p);
		ressort->ChangeDirection(0, 1); //va savoir pourquoi
		ressort->Start();
	}
}