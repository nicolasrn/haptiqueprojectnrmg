#include "TerrainHaptique.h"

TerrainHaptique::TerrainHaptique(GUITerrain *fenetre, Terrain *terrain) : TerrainTresGlissantHaptique(fenetre, terrain),
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

	this->mEnclos->ChangeInsideEffect(mTexture);

	mGran = mProjet->CreateEffect("TerrainGran", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD);
	if (!mGran)
	{
		delete mGran;
		mGran = NULL;
	}
}

TerrainHaptique::~TerrainHaptique()
{
	if (mTexture != NULL)
		delete mTexture;
	if (mGran != NULL)
		delete mGran;

	mTexture = NULL;
	mGran = NULL;
}

void TerrainHaptique::recentrer()
{
	TerrainTresGlissantHaptique::recentrer();
}

void TerrainHaptique::Start()
{
	//mGran->Start();
	//mTexture->Start();
	TerrainTresGlissantHaptique::Start();
}

void TerrainHaptique::Stop()
{
	//mGran->Stop();
	//mTexture->Stop();
	TerrainTresGlissantHaptique::Stop();
}
