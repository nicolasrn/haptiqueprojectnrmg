#include "Raquette.h"

Raquette::Raquette(const int &x, const int &y, const int &idJoueur) : Element(x, y, 30, 30), idJoueur(idJoueur)
{
}

Raquette::~Raquette()
{
}

int Raquette::getIdJoueur()const
{
	return idJoueur;
}

void Raquette::setIdJoueur(const int &idJoueur)
{
	this->idJoueur = idJoueur;
}