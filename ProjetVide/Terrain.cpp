#include "Terrain.h"

Terrain::Terrain(const int &width, const int &height) : width(width), height(height)
{
	//initialisation des composants
	human = new Raquette(width/2, 2*height/3);
	ia = new Raquette(width/2, height / 3);

	palet = new Palet(width/2, height/2);
}

Terrain::~Terrain()
{
	delete human;
	delete ia;
	delete palet;
}
