#pragma once

#ifndef __TERAINNORMALE__
#define __TERAINNORMALE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "TerrainHaptique.h"

class TerrainNormalHaptique : public TerrainHaptique
{
private:
	CImmFriction *mFriction;

public:
	TerrainNormalHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainNormalHaptique();
	
};

#endif