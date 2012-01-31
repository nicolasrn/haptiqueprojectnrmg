/*!
 * \file Element.h
 * Fichier concernant un Element
 */

#ifndef __ELEMENT__
#define __ELEMENT__

#pragma once

/*!
 * Classe abstraite représentant un element metier
 */
class Element
{
protected:
	/*!< Abscisse */
	double x;

	/*!< Ordonnée */
	double y;

	/*!< largeur */
	double width;

	/*!< hauteur */
	double height;
	
	/*!< coefficient de vitesse selon le contexte */
	double vitesseTerrain;

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de l'objet
	 * \param x : Abscisse
	 * \param y : Ordonnée
	 */
	Element(const double &x, const double &y, const double &width = 0, const double &height = 0, const double &vitesseTerrain = 1) : x(x), y(y), width(width), height(height), vitesseTerrain(vitesseTerrain)
	{
	}

	/*!
	 * \brief Getteur de x
	 * Getteur de x
	 */
	virtual double getX() const
	{
		return x;
	}

	/*!
	 * \brief Getteur de y
	 * Getteur de y
	 */
	virtual double getY() const
	{
		return y;
	}
	
	/*!
	 * \brief Setteur de x
	 * Setteur de x
	 * \param x : nouvelle abscisse
	 */
	virtual void setX(const double &x)
	{
		this->x = x;
	}
	
	/*!
	 * \brief Setteur de y
	 * Setteur de y
	 * \param y : nouvelle abscisse
	 */
	virtual void setY(const double &y)
	{
		this->y = y;
	}

	/*!
	 * \brief Getteur de width
	 * Getteur de width
	 */
	virtual double getWidth()const
	{
		return width;
	}
	
	/*!
	 * \brief Getteur de height
	 * Getteur de height
	 */
	virtual double getHeight()const
	{
		return height;
	}
	
	/*!
	 * \brief Setteur de width
	 * Setteur de width
	 */
	virtual void setWidth(const double &width)
	{
		this->width = width;
	}
	
	/*!
	 * \brief Setteur de height
	 * Setteur de height
	 */
	virtual void setHeight(const double &height)
	{
		this->height = height;
	}
	
	/*!
	 * \brief Getteur de la vitesse induite par le terrain
	 * Getteur du vecteur de deplacement sur x
	 */
	virtual double getVitesseTerrain()const
	{
		return vitesseTerrain;
	}
	
	/*!
	 * \brief Setteur de la vitesse induite par le terrain
	 * Setteur du vecteur de deplacement sur x
	 */
	virtual void setVitesseTerrain(const double &vitesseTerrain)
	{
		this->vitesseTerrain = vitesseTerrain;
	}
	
};

#endif