#include "TerrainNormalHaptique.h"


TerrainNormalHaptique::TerrainNormalHaptique(GUITerrain *fenetre, Terrain *terrain) : TerrainHaptique(fenetre, terrain),
	mProjet(NULL), mTexture(NULL), mGran(NULL)
{
	mProjet = new CImmProject();
	if (mProjet->OpenFile("RetoursHaptiques.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		mTexture = new CImmTexture();
		if (!mTexture->InitializeFromProject(*mProjet, "Texture", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete mTexture;
			mTexture = NULL;
		}
	}

	//this->mEnclos->ChangeInsideEffect(mTexture);

	mGran = mProjet->CreateEffect("TerrainGran", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD);
	if (!mGran)
	{
		delete mGran;
		mGran = NULL;
	}
}


TerrainNormalHaptique::~TerrainNormalHaptique()
{
	if (mTexture != NULL)
		delete mTexture;
	if (mGran != NULL)
		delete mGran;

	mTexture = NULL;
	mGran = NULL;
}
