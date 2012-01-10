#include "Terrain.h"

Terrain::Terrain(const int &width, const int &height) : Element(0, 0, width, height), yStart(0)
{
	list = std::vector<Element*>();
	//initialisation des composants
	human = new Raquette(width/2, 3*height/8);
	ia = new Raquette(width/2, height / 8);

	butNord = new But(width/4, 0, width/2);
	butSud  = new But(width/4, height-48, width/2);

	list.push_back(human);
	list.push_back(ia);
	
	//list.push_back(butNord);
	//list.push_back(butSud);

	//list.push_back(this);

	palet = new Palet(width/2, height/2);
}

Terrain::~Terrain()
{
	delete human;
	delete ia;
	delete palet;
	delete butNord;
	delete butSud;

	human = NULL;
	ia = NULL;
	palet = NULL;
	butNord = NULL;
	butSud = NULL;
}
