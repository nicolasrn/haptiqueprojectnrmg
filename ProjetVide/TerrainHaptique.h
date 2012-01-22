#pragma once

#ifndef __GUITERRAINHAPTIQUE__
#define __GUITERRAINHAPTIQUE__

#include <IFC.h>

#include "TerrainTresGlissantHaptique.h"
#include "GestionnaireSouris.h"

class TerrainHaptique : public TerrainTresGlissantHaptique
{
private:
	CImmProject *mProjet;

	CImmTexture *mTexture;

	CImmCompoundEffect *mGran;

public:
	TerrainHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainHaptique();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

#endif