/*!
 * \file Palet.h
 * Fichier concernant le modele du palet
 */
#pragma once

#ifndef __PALET__
#define __PALET__

#include "Element.h"

/*!
 * \brief Représente le modele du palet
 */
class Palet : public Element
{
private:
	int xOld, yOld;/*!< Anciennes coordonnées */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param x : l'abscisse
	 * \param x : l'ordonnées
	 */
	Palet(const int &x, const int &y);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	~Palet(void);

	/*!
	 * \brief Setteur de x
	 * Setteur de x
	 * \param x : nouvelle abscisse
	 */
	void setX(const int &x)
	{
		this->xOld = this->x;
		this->x = x;
	}
	
	/*!
	 * \brief Setteur de y
	 * Setteur de y
	 * \param y : nouvelle abscisse
	 */
	void setY(const int &y)
	{
		this->yOld = this->y;
		this->y = y;
	}
	
};

#endif