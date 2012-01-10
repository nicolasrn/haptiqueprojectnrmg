#include "Palet.h"


Palet::Palet(const int &x, const int &y) : Element(x, y, 20, 20), /*xOld(x), yOld(y),*/ vx(0), vy(0)
{
}

Palet::~Palet(void)
{
}

void Palet::setVecteurDeplacement(const int &vx, const int &vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Palet::compute()
{
	this->setX(this->getX()+vx);
	this->setY(this->getY()+vy);
}