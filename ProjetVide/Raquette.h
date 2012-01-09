/*!
 * \file Raquette.h
 * Fichier concernant le modele de la Raquette
 */

#pragma once

#ifndef __RAQUETTE__
#define __RAQUETTE__

#include "Element.h"

/*!
 * \brief Représente le modele de la raquette
 */
class Raquette : public Element
{

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param x : l'abscisse
	 * \param x : l'ordonnées
	 */
	Raquette(const int &x, const int &y);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	~Raquette(void);
	
};

#endif