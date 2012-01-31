#include "TerrainTresGlissantHaptique.h"

TerrainTresGlissantHaptique::TerrainTresGlissantHaptique(GUITerrain *fenetre, Terrain *terrain) :
	TerrainHaptique(fenetre, terrain)
{
	terrain->setVitesseTerrain(2);
}

TerrainTresGlissantHaptique::~TerrainTresGlissantHaptique()
{

}
