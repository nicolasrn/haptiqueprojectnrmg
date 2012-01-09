/*!
 * \file GestionCollision.h
 * Fichier concernant la gestion des collisions
 */

#pragma once

#ifndef __GCOLLISION__
#define __GCOLLISION__

#include <iostream>
#include <vector>

#include "Palet.h"
#include "Element.h"

/*!
 * \brief classe gérant les collisions
 */
class GestionCollision
{
public:
	/*!
	 * \brief charge de detecter les collisions
	 * charge de detecter les collisions
	 * \param a : le palet
	 * \param b : le reste
	 * \return bool : true si ou false sinon
	 */
	static bool isCollisionBetween(Palet *a, std::vector<Element *> b)
	{
		bool collision = false;
		for(std::vector<Element*>::iterator i = b.begin(); i != b.end(); i++)
		{
			//(*i)->
		}
		return collision;
	}
};

#endif