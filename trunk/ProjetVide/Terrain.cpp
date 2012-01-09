#include "Terrain.h"

Terrain::Terrain(const int &width, const int &height) : Element(0, 0, width, height)
{
	list = std::vector<Element*>();
	//initialisation des composants
	human = new Raquette(width/2, 2*height/3);
	ia = new Raquette(width/2, height / 3);

	list.push_back(human);
	list.push_back(ia);

	palet = new Palet(width/2, height/2);
}

Terrain::~Terrain()
{
	delete human;
	delete ia;
	delete palet;
}

void Terrain::traitementCollision()
{
	GestionCollision::isCollisionBetween(palet, list);
}