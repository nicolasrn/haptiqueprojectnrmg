/*!
 * \file GestionCollision.h
 * Fichier concernant la gestion des collisions
 */

#pragma once

#ifndef __GCOLLISION__
#define __GCOLLISION__

#include <iostream>
#include <vector>
#include <cmath>

#include "Palet.h"
#include "Terrain.h"
#include "Element.h"

/*!
 * \brief classe gérant les collisions
 */
class GestionCollision
{
public:
	/*!
	 * \brief calcul la distance entre 2 points
	 * calcul la distance entre 2 points dans un repere orthogonal
	 * \param x1 : abscisse du premier point
	 * \param y1 : ordonnee du premier point
	 * \param x2 : abscisse du second point
	 * \param y2 : ordonnee du second point
	 * \return double : la distance
	 */
	static double distance( int x1, int y1, int x2, int y2 );
	
	/*!
	 * \brief charge de detecter les collisions entre des objets circulaires
	 * charge de detecter les collisions entre des objets circulaires
	 * \param a : le palet
	 * \param b : le reste
	 * \param elt : en sortie retourne l'objet qui est entré en collision avec le palet
	 * \return bool : true si ou false sinon
	 */
	static bool isCircleCollisionBetween(Palet *a, std::vector<Element *> list, Element **elt);

	/*!
	 * \brief charge de detecter les collisions entre des objets cercle et le terrain
	 * charge de detecter les collisions entre des objets cercle et le terrain
	 * \param A : le palet
	 * \param B : le terrain
	 * \param dx : resolution de la direction
	 * \param dy : resolution de la direction
	 * \return bool : true si ou false sinon
	 */
	static bool isCircleGroundCollisionBetween(Palet *p, Terrain *t, int *dx, int *dy);
};

#endif