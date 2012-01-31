#include "GestionCollision.h"

double GestionCollision::distance( int x1, int y1, int x2, int y2 )
{
	//Retourne la distance entre deux points
	return sqrt(pow((double)x2 - x1, 2) + pow((double)y2 - y1, 2 ));
}
	
bool GestionCollision::isCircleCollisionBetween(Palet *a, std::vector<Element *> list, Element **elt)
{
	for(std::vector<Element*>::iterator b = list.begin(); b != list.end(); ++b)
	{
		if (GestionCollision::distance(a->getX(), a->getY(), (*b)->getX(), (*b)->getY()) < (a->getWidth() + (*b)->getWidth()))
		{
			*elt = (*b);
			return true;
		}
	}
	return false;
}

bool GestionCollision::isCircleGroundCollisionBetween(Palet *p, Terrain *t, double *dx, double *dy)
{
	bool collision = false;
	//détection a gauche du terrain
	if (p->getX() - p->getWidth() <= 0)
	{
		collision = true;
		*dx = 1;
	}

	//a droite
	if (p->getX() + p->getWidth()*2 >= t->getWidth())
	{
		collision = true;
		*dx = -1;
	}
	
	//en haut
	if (p->getY() - p->getHeight() <= t->getYStart())
	{
		collision = true;
		*dy = 1;
	}

	//en bas
	if (p->getY() + p->getHeight()*3 >= t->getHeight())
	{
		collision = true;
		*dy = -1;
	}

	//detection du but si ...

	return collision;
}