#include "PaletHaptique.h"

PaletHaptique::PaletHaptique(GUITerrain *fenetre, Terrain *terrain) : ElementHaptique(), fenetre(fenetre), terrain(terrain), mEnclos(NULL)
{
	this->mCentreEnclosRelatif = wxPoint(terrain->getPalet()->getX(), terrain->getPalet()->getY() + terrain->getYStart());
	if (mEnclos == NULL)
	{
		this->mEnclos = new CImmEllipse();
		wxPoint temp(this->mCentreEnclosRelatif);
		fenetre->ClientToScreen(&temp.x, &temp.y);
		POINT centreEnclos;
		centreEnclos.x = temp.x;
		centreEnclos.y = temp.y;
		if (!mEnclos->Initialize(GestionnaireSouris::getInstance()->getSouris(), //device
			terrain->getPalet()->getWidth()*2 + terrain->getHuman()->getWidth()*2, terrain->getPalet()->getHeight()*2 + terrain->getHuman()->getWidth()*2, //width, height taille du palet + taille de la raquette
			100000, //stiffness
			10,//wall width
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
	}
}

PaletHaptique::~PaletHaptique()
{
	if (mEnclos != NULL)
		delete mEnclos;
	mEnclos = NULL;
}

void PaletHaptique::recentrer()
{
	wxPoint centre(mCentreEnclosRelatif);
	fenetre->ClientToScreen(&centre.x, &centre.y);
	mEnclos->ChangeCenter(centre.x, centre.y);
}

void PaletHaptique::setCentreRelatif(const int &x, const int &y)
{
	this->mCentreEnclosRelatif.x = x;
	this->mCentreEnclosRelatif.y = y;
	wxPoint centre(mCentreEnclosRelatif);
	fenetre->ClientToScreen(&centre.x, &centre.y);
	mEnclos->ChangeCenter(centre.x, centre.y);
}

void PaletHaptique::Start()
{
	this->mEnclos->Start();
}

void PaletHaptique::Stop()
{
	this->mEnclos->Stop();
}