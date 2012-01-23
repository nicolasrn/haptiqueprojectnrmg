#pragma once

#ifndef __TERRAINGLUANT__
#define __TERRAINGLUANT__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "TerrainHaptique.h"

class TerrainGluantHaptique : public TerrainHaptique
{
private:
	CImmTexture *mTexture;

public:
	TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainGluantHaptique();

};

#endif