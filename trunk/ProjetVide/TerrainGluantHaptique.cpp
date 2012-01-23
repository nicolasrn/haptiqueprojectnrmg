#include "TerrainGluantHaptique.h"


TerrainGluantHaptique::TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain) : 
	TerrainHaptique(fenetre, terrain), mTexture(NULL)
{
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		mTexture = new CImmTexture();
		if (!mTexture->InitializeFromProject(*mProjet, "gluant", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete mTexture;
			mTexture = NULL;
			wxMessageBox("erreur mTexture");
		}
		mTexture->ChangePositiveBumpSpacing(1);
		this->mEnclos->ChangeInsideEffect(mTexture);
	}
}

TerrainGluantHaptique::~TerrainGluantHaptique()
{
	if (mTexture != NULL)
		delete mTexture;
	mTexture = NULL;
}
