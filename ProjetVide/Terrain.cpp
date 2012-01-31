#include "Terrain.h"

Terrain::Terrain(const double &width, const double &height) : Element(0, 0, width, height), yStart(0)
{
	list = std::vector<Element*>();
	//initialisation des composants
	srand((unsigned int)NULL);
	human = new Raquette(width/2, 3*height/8, 235);
	ia = new Raquette(width/2, height / 8, 140);

	butNord = new But(width/4, 0, width/2);
	butSud  = new But(width/4, height-48, width/2);

	list.push_back(human);
	list.push_back(ia);
	
	//list.push_back(butNord);
	//list.push_back(butSud);

	//list.push_back(this);

	palet = new Palet(width/2, (height - yStart)/2);
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

Raquette* Terrain::getHuman()
{
	return human;
}
	
Raquette* Terrain::getIa()
{
	return ia;
}
	
Palet* Terrain::getPalet()
{
	return palet;
}
	
But* Terrain::getButNord()
{
	return butNord;
}
	
But* Terrain::getButSud()
{
	return butSud;
}

std::vector<Element*> Terrain::getList()
{
	return list;
}

double Terrain::getYStart()const
{
	return yStart;
}

void Terrain::setYStart(const double &ystart)
{
	this->yStart = ystart;
	palet->setY(palet->getY() - ystart/2);
}

void Terrain::setVitesseTerrain(const double &vitesseTerrain)
{
	Element::setVitesseTerrain(vitesseTerrain);
	this->human->setVitesseTerrain(vitesseTerrain);
	this->ia->setVitesseTerrain(vitesseTerrain);
	this->palet->setVitesseTerrain(vitesseTerrain);
}