#include "GUITerrainHaptique.h"

GUITerrainHaptique::GUITerrainHaptique(wxWindow *parent, Terrain *terrain) : GUITerrain(parent, terrain), mEnclos(NULL), mTexture(NULL)
{
	mCentreEnclosRelatif = wxPoint(this->GetSize().GetWidth()/2, this->GetSize().GetHeight()/2);

	mTexture = new CImmTexture();
	FEELIT_EFFECT effect;
	if (!mTexture->initialize(GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))//Initialize(GestionnaireSouris::getInstance()->getSouris(), effect, IMM_PARAM_NODOWNLOAD))
	{
		wxPoint temp(mCentreEnclosRelatif);
		ClientToScreen(&temp.x, &temp.y);
		POINT centreEnclos;
		centreEnclos.x = temp.x;
		centreEnclos.y = temp.y;

		mTexture->ChangePositiveBumpMag(1000000);
		mTexture->ChangeNegativeBumpMag(1000000);
		mTexture->ChangePositiveBumpSpacing(1);
		mTexture->ChangeNegativeBumpSpacing(1);
		mTexture->ChangePositiveBumpWidth(5);
		mTexture->ChangeNegativeBumpWidth(5);
		mTexture->ChangeOffset(centreEnclos);
	}
	else
	{
		delete mTexture;
		mTexture = NULL;
		throw std::exception("erreur d'initialisation de l'effet");
	}

	if (mEnclos == NULL)
	{
		mEnclos = new CImmEnclosure();
		wxPoint temp(mCentreEnclosRelatif);
		ClientToScreen(&temp.x, &temp.y);
		POINT centreEnclos;
		centreEnclos.x = temp.x;
		centreEnclos.y = temp.y;
		if (!mEnclos->Initialize(GestionnaireSouris::getInstance()->getSouris(),
			this->GetSize().GetWidth(), this->GetSize().GetHeight(), // dimensions
				-10000, -10000, //dureté des murs
				10, 10, //épaisseur des murs
				10000, 10000, //saturation des murs/force max
				IMM_STIFF_ANYWALL,//masque d’application du retour
				0x0, //masque de clipping
				centreEnclos, //centre
				NULL, //effet dans l’enclos
				0, //angle de rotation de l’enclos, exprimé en centigrade
				//45° ⇒ 4500 !!!
				IMM_PARAM_NODOWNLOAD))
		{
			delete mEnclos;
			mEnclos = NULL;

			throw std::exception("erreur initialisation enclos terrain");
		}
		mEnclos->ChangeInsideEffect(mTexture);
		mTexture->Start();
		mEnclos->Start();
	}
}

GUITerrainHaptique::~GUITerrainHaptique()
{
	if (mEnclos != NULL)
		delete mEnclos;
	if (mTexture != NULL);
		delete mTexture;
	mTexture = NULL;
	mEnclos = NULL;
}

CImmEnclosure* GUITerrainHaptique::getEnclos()
{
	return this->mEnclos;
}

wxPoint& GUITerrainHaptique::getCentreEnclosRelatif()
{
	return this->mCentreEnclosRelatif;
}