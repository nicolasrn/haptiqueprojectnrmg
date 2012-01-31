#include "Palet.h"

Palet::Palet(const double &x, const double &y) : Element(x, y, 20, 20), Observable(), /*xOld(x), yOld(y),*/ vx(0), vy(0), ref(0), delai(0)
{
	delai = 1000;
}

Palet::~Palet(void)
{
}

void Palet::setVecteurDeplacement(const double &vx, const double &vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Palet::compute()
{
	//*
	if (ref == 0)
		ref = clock();

	if (ref + delai < clock())
	{
		if (vx < 0 && vx < 1)
			vx += 0.1;
		else if (-1 < vx && vx > 0)
			vx -= 0.1;

		if (vy < 0 && vy < 1)
			vy += 0.1;
		else if (-1 < vy && vy > 0)
			vy -= 0.1;

		ref = 0;
	}//*/

	this->setX((this->getX()+vx*this->getVitesseTerrain()));
	this->setY((this->getY()+vy*this->getVitesseTerrain()));
}