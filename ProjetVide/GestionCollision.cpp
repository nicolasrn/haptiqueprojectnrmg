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

bool GestionCollision::isCircleSquareCollisionBetween(Palet *A, Element *B)
{
	int leftAv, leftAh, leftB;
	int rightAv, rightAh, rightB;
	int topAv, topAh, topB;
	int bottomAv, bottomAh, bottomB;

	//Les angles de la box B
	int Bx1, By1;
	int Bx2, By2;
	int Bx3, By3;
	int Bx4, By4;

	//Calcul des cotés de A
	leftAv = A->getX();
	rightAv = A->getX();
	topAv = A->getY() - A->getWidth();
	bottomAv = A->getY() + A->getWidth();

	leftAh = A->getX() - A->getWidth();
	rightAh = A->getX() + A->getWidth();
	topAh = A->getY();
	bottomAh = A->getY();

	//On va dans la boite B
	//for( int Bbox = 0; Bbox < B.size(); Bbox++ )
	//{
		//Calcul des cotés de B
		leftB = B->getX();
		rightB = B->getX() + B->getWidth();
		topB = B->getY();
		bottomB = B->getY() + B->getHeight();

		//Calcul des angles de B
		Bx1 = B->getX(), By1 = B->getY();
		Bx2 = B->getX() + B->getWidth(), By2 = B->getY();
		Bx3 = B->getX(), By3 = B->getY() + B->getHeight();
		Bx4 = B->getX() + B->getWidth(), By4 = B->getY() + B->getHeight();

		//Si aucun coté de la verticale A est en dehors de B
		if( ( ( bottomAv <= topB ) || ( topAv >= bottomB ) || ( rightAv <= leftB ) || ( leftAv >= rightB ) ) == false )
		{
			//Une collision est détécté
			return true;
		}

		//Si aucun coté de l'horizontale A est en dehors de B
		if( ( ( bottomAh <= topB ) || ( topAh >= bottomB ) || ( rightAh <= leftB ) || ( leftAh >= rightB ) ) == false )
		{
			//Une collision est détécté
			return true;
		}

		//Si un des coins de B est dans A
		if( ( GestionCollision::distance( A->getX(), A->getY(), Bx1, By1 ) < A->getWidth() ) || ( distance( A->getX(), A->getY(), Bx2, By2 ) < A->getWidth() ) || ( distance( A->getX(), A->getY(), Bx3, By3 ) < A->getWidth() ) || ( distance( A->getX(), A->getY(), Bx4, By4 ) < A->getWidth() ) )
		{
			//Une collision est détécté
			return true;
		}
	//}

	//Pas de collision
	return false;
}

bool GestionCollision::isCircleGroundCollisionBetween(Palet *p, Terrain *t, int *dx, int *dy)
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