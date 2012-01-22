#include "TerrainGluantHaptique.h"


TerrainGluantHaptique::TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain) : TerrainTresGlissantHaptique(fenetre, terrain)
{
}


TerrainGluantHaptique::~TerrainGluantHaptique()
{
}

void TerrainGluantHaptique::recentrer()
{
	TerrainTresGlissantHaptique::recentrer();
}

void TerrainGluantHaptique::Start()
{
	TerrainTresGlissantHaptique::Start();
}

void TerrainGluantHaptique::Stop()
{
	TerrainTresGlissantHaptique::Stop();
}