#pragma once

#ifndef __GUITERRAINHAPTIQUE__
#define __GUITERRAINHAPTIQUE__

#include <IFC.h>

#include "ElementHaptique.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"
#include "GUITerrain.h"

class TerrainHaptique : public ElementHaptique
{
private:
	Terrain *terrain;

	GUITerrain *fenetre;

	CImmProject *mProjet;

	wxPoint mCentreEnclosRelatif;
	CImmEnclosure *mEnclos;
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