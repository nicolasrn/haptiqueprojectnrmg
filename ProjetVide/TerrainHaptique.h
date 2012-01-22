#pragma once

#ifndef __TERRAINHAPTIQUE__
#define __TERRAINHAPTIQUE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GUITerrain.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"

class TerrainHaptique : public ElementHaptique
{
protected:
	GUITerrain *fenetre;
	Terrain *terrain;

	wxPoint mCentreEnclosRelatif;
	CImmEnclosure *mEnclos;

public:
	TerrainHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainHaptique();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

#endif