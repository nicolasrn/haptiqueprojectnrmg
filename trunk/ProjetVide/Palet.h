/*!
 * \file Palet.h
 * Fichier concernant le modele du palet
 */
#pragma once

#ifndef __PALET__
#define __PALET__

#include "Element.h"
#include "Observer.h"

/*!
 * \brief Représente le modele du palet
 */
class Palet : public Element, public Observable
{
private:
	//int xOld, yOld;/*!< Anciennes coordonnées */
	int vx, vy; /*!< Coordonnee du vecteur de deplacement */

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
	virtual ~Palet(void);

	/*!
	 * \brief Defini le vecteur de deplacement du pale
	 * Defini le vecteur de deplacement du pale
	 * \param vx : abscisse du vecteur
 	 * \param vy : ordonnee du vecteur
	 */
	void setVecteurDeplacement(const int &vx, const int &vy);

	/*!
	 * \brief Lance le deplacement
	 * Lance le deplacement
	 */
	void compute();
	
	/*!
	 * \brief Getteur du vecteur de deplacement sur x
	 * Getteur du vecteur de deplacement sur x
	 */
	int getVx()const
	{
		return vx;
	}
	
	/*!
	 * \brief Getteur du vecteur de deplacement sur y
	 * Getteur du vecteur de deplacement sur y
	 */
	int getVy()const
	{
		return vy;
	}

	/*!
	 * \brief Setteur de x
	 * Setteur de x
	 * \param x : nouvelle abscisse
	 */
	/*void setX(const int &x)
	{
		this->xOld = this->x;
		this->x = x;
	}
	
	/*!
	 * \brief Setteur de y
	 * Setteur de y
	 * \param y : nouvelle abscisse
	 */
	/*void setY(const int &y)
	{
		this->yOld = this->y;
		this->y = y;
	}*/
	
};

#endif