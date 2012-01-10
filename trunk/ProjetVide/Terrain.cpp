#include "Terrain.h"

Terrain::Terrain(const int &width, const int &height) : Element(0, 0, width, height), yStart(0)
{
	list = std::vector<Element*>();
	//initialisation des composants
	human = new Raquette(width/2, 3*height/8);
	ia = new Raquette(width/2, height / 8);

	list.push_back(human);
	list.push_back(ia);
	//list.push_back(this);

	palet = new Palet(width/2, height/2);
}

Terrain::~Terrain()
{
	delete human;
	delete ia;
	delete palet;
}
