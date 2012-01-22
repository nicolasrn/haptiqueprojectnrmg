#pragma once

#ifndef __TERRAINGLISSANT__
#define __TERRAINGLISSANT__

#include <IFC.h>
#include "TerrainHaptique.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "GestionnaireSouris.h"

class TerrainTresGlissantHaptique : public TerrainHaptique
{
public:
	TerrainTresGlissantHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	virtual ~TerrainTresGlissantHaptique();
	
};

#endif