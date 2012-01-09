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
	int x;

	/*!< Ordonnée */
	int y;

	/*!< largeur */
	int width;

	/*!< hauteur */
	int height;

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de l'objet
	 * \param x : Abscisse
	 * \param y : Ordonnée
	 */
	Element(const int &x, const int &y, const int &width = 0, const int &height = 0) : x(x), y(y), width(width), height(height)
	{
	}

	/*!
	 * \brief Getteur de x
	 * Getteur de x
	 */
	virtual int getX() const
	{
		return x;
	}

	/*!
	 * \brief Getteur de y
	 * Getteur de y
	 */
	virtual int getY() const
	{
		return y;
	}
	
	/*!
	 * \brief Setteur de x
	 * Setteur de x
	 * \param x : nouvelle abscisse
	 */
	virtual void setX(const int &x)
	{
		this->x = x;
	}
	
	/*!
	 * \brief Setteur de y
	 * Setteur de y
	 * \param y : nouvelle abscisse
	 */
	virtual void setY(const int &y)
	{
		this->y = y;
	}

	/*!
	 * \brief Getteur de width
	 * Getteur de width
	 */
	virtual int getWidth()const
	{
		return width;
	}
	
	/*!
	 * \brief Getteur de height
	 * Getteur de height
	 */
	virtual int getHeight()const
	{
		return height;
	}

};

#endif