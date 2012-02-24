#include "Raquette.h"

Raquette::Raquette(const double &x, const int &y, const int &idJoueur) : Element(x, y, 30, 30), idJoueur(idJoueur), vecteurDirecteurX(0)
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

void Raquette::deplacer(const double &x, const double &y)
{
	this->setX(x/* * this->getVitesseTerrain()*/);
	this->setY(y/* * this->getVitesseTerrain()*/);
}

void Raquette::deplacer()
{
	this->setX(x + vecteurDirecteurX/* * this->getVitesseTerrain()*/);
	this->setY(y/* * this->getVitesseTerrain()*/);
}

void Raquette::setVecteurX(const double &vx)
{
	this->vecteurDirecteurX = vx;
}

double Raquette::getVecteurX()const
{
	return this->vecteurDirecteurX;
}