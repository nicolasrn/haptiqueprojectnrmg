#pragma once

#ifndef __TERRAINGLUANT__
#define __TERRAINGLUANT__

#include "TerrainHaptique.h"

class TerrainGluantHaptique : public TerrainHaptique
{
public:
	TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~TerrainGluantHaptique();

};

#endif