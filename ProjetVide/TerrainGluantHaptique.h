#pragma once

#include "TerrainTresGlissantHaptique.h"

class TerrainGluantHaptique : public TerrainTresGlissantHaptique
{
public:
	TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain);
	virtual ~TerrainGluantHaptique();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

