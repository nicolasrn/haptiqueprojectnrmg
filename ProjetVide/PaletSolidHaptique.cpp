#include "PaletSolidHaptique.h"

PaletSolidHaptique::PaletSolidHaptique(GUITerrain *fenetre, Terrain *terrain) : ElementHaptique(), Observer(),
	fenetre(fenetre), terrain(terrain)/*, mEnclos(NULL)*/, force(NULL)
{
	/*this->mCentreEnclosRelatif = wxPoint(terrain->getPalet()->getX(), terrain->getPalet()->getY());
	if (mEnclos == NULL)
	{
		this->mEnclos = new CImmEllipse();
		wxPoint temp(this->mCentreEnclosRelatif);
		fenetre->ClientToScreen(&temp.x, &temp.y);
		POINT centreEnclos;
		centreEnclos.x = temp.x;
		centreEnclos.y = temp.y;
		if (!mEnclos->Initialize(GestionnaireSouris::getInstance()->getSouris(), //device
			terrain->getPalet()->getWidth()*2 + terrain->getHuman()->getWidth()*2, terrain->getPalet()->getHeight()*2 + terrain->getHuman()->getHeight()*2, //width, height taille du palet + taille de la raquette
			100000, //stiffness
			15,//wall width
			100000,//saturation
			IMM_STIFF_OUTERANYWALL,//stiffnessmask
			IMM_CLIP_OUTERANYWALL, //clipping mask
			centreEnclos,//centre
			NULL,//innereffect
			0,//angle
			IMM_PARAM_NODOWNLOAD))
		{
			delete mEnclos;
			mEnclos = NULL;

			throw std::exception("erreur initialisation enclos terrain");
		}
	}*/

	force = new CImmRamp();
	if (!force->Initialize(GestionnaireSouris::getInstance()->getSouris(), 
		1L, 1L, //direction x, y
		500, //duree
		5000, 5000, //force debut, fin
		(LPFEELIT_ENVELOPE)0,IMM_PARAM_NODOWNLOAD))
	{
		delete force;
		force = NULL;
	}
}

PaletSolidHaptique::~PaletSolidHaptique()
{
	//if (mEnclos != NULL)
	//	delete mEnclos;
	if (force != NULL)
		delete force;

	//mEnclos = NULL;
	force = NULL;
}

void PaletSolidHaptique::recentrer()
{
	//wxPoint centre(mCentreEnclosRelatif);
	//fenetre->ClientToScreen(&centre.x, &centre.y);
	//mEnclos->ChangeCenter(centre.x, centre.y);
}

void PaletSolidHaptique::setCentreRelatif(const int &x, const int &y)
{
	//this->mCentreEnclosRelatif.x = x;
	//this->mCentreEnclosRelatif.y = y;
	//wxPoint centre(mCentreEnclosRelatif);
	//fenetre->ClientToScreen(&centre.x, &centre.y);
	//mEnclos->ChangeCenter(centre.x, centre.y);
}

void PaletSolidHaptique::Start()
{
	//this->mEnclos->Start();
}

void PaletSolidHaptique::Stop()
{
	//this->mEnclos->Stop();
}

void PaletSolidHaptique::update(Observable *o, Data *data)
{
	DataCoordonnee *d = dynamic_cast<DataCoordonnee*>(data);
	if (d != NULL)
	{
		DataCoordonnee *d = (DataCoordonnee*)data;
		long anglex = d->vx, angley = d->vy;
		//this->setCentreRelatif(d->x, d->y);

		force->ChangeDirection(anglex, angley);
		force->Start();
	}
}