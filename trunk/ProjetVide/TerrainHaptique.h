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

	wxPoint mCentreEnclosRelatif;
	CImmEnclosure *mEnclos;

	GUITerrain *fenetre;
public:
	TerrainHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainHaptique();

	virtual void recentrer();
};

#endif