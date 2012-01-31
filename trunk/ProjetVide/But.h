/*!
 * \file but.h
 * Fichier metier representant un but
 */

#pragma once

#ifndef __BUT__
#define __BUT__

#include "element.h"

/*!
 * \brief Classe metier du But
 * Classe metier du But
 */
class But : public Element
{
public:
	/*!
	 * \brief Constructeur
	 * Constructeur de la classe
	 * \param x : abscisse
	 * \param y : ordonnee
	 * \param width : la taille
	 */
	But(const double &x, const double &y, const double &width);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~But();
};

#endif