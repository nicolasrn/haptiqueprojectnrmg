#pragma once

#include <IFC.h>
#include "ElementHaptique.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "GestionnaireSouris.h"

class TerrainTresGlissantHaptique : public ElementHaptique
{
protected:
	GUITerrain *fenetre;
	Terrain *terrain;

	wxPoint mCentreEnclosRelatif;
	CImmEnclosure *mEnclos;

public:
	TerrainTresGlissantHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	virtual ~TerrainTresGlissantHaptique();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

