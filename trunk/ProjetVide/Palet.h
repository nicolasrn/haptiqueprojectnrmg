/*!
 * \file Palet.h
 * Fichier concernant le modele du palet
 */
#pragma once

#ifndef __PALET__
#define __PALET__

#include "Element.h"
#include "Observer.h"
#include <ctime>

/*!
 * \brief Représente le modele du palet
 */
class Palet : public Element, public Observable
{
private:
	//int xOld, yOld;/*!< Anciennes coordonnées */
	double vx, vy; /*!< Coordonnee du vecteur de deplacement */
	clock_t ref; /*!< le temps de reference */
	clock_t delai; /*!< le delai d'attente */
	
public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param x : l'abscisse
	 * \param y : l'ordonnées
	 */
	Palet(const double &x, const double &y);
	
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
	void setVecteurDeplacement(const double &vx, const double &vy);

	/*!
	 * \brief Lance le deplacement
	 * Lance le deplacement
	 */
	void compute();
	
	/*!
	 * \brief Getteur du vecteur de deplacement sur x
	 * Getteur du vecteur de deplacement sur x
	 */
	double getVx()const
	{
		return vx;
	}
	
	/*!
	 * \brief Getteur du vecteur de deplacement sur y
	 * Getteur du vecteur de deplacement sur y
	 */
	double getVy()const
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