#include "TerrainNormalHaptique.h"


TerrainNormalHaptique::TerrainNormalHaptique(GUITerrain *fenetre, Terrain *terrain) : TerrainHaptique(fenetre, terrain),
	mFriction(NULL)
{
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		mFriction = new CImmFriction();
		if (!mFriction->InitializeFromProject(*mProjet, "Friction", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete mFriction;
			mFriction = NULL;
			wxMessageBox("erreur friction");
		}
		this->mEnclos->ChangeInsideEffect(mFriction);
	}

}

TerrainNormalHaptique::~TerrainNormalHaptique()
{
	if (mFriction != NULL)
		delete mFriction;
	mFriction = NULL;
}
