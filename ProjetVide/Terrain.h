/*!
 * \file Terrain.h
 * Fichier concernant le modele du terrain
 */

#pragma once

#ifndef __TERRAIN__
#define __TERRAIN__

#include <iostream>
#include <vector>
#include <wx/panel.h>

#include "Element.h"
#include "Raquette.h"
#include "Palet.h"
#include "But.h"

/*!
 * \brief Représente le modele du terrain
 */
class Terrain : public Element
{
private:
	std::vector<Element*> list; /*! Liste des objets présents sur le terrain */
	Raquette *human, *ia;/*!< Raquete du joueur de l'ordinateur */
	Palet *palet;/*!< Le palet */
	But *butNord, *butSud; /*!< Represente les 2 buts */
	int yStart; /*!< Position a partir de laquelle le terrain commence sur la GUI*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param width : l'abscisse
	 * \param height : l'ordonnées
	 */
	Terrain(const int &width, const int &height);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	~Terrain();

	/*!
	 * \brief Getteur
	 * Getteur de la raquette du joueur
	 */
	Raquette *getHuman()
	{
		return human;
	}
	
	/*!
	 * \brief Getteur
	 * Getteur de la raquette de l'ordinateur
	 */
	Raquette *getIa()
	{
		return ia;
	}
	
	/*!
	 * \brief Getteur
	 * Getteur du palet
	 */
	Palet *getPalet()
	{
		return palet;
	}
	
	/*!
	 * \brief Getteur
	 * Getteur du butNord
	 */
	But *getButNord()
	{
		return butNord;
	}
	
	/*!
	 * \brief Getteur
	 * Getteur du butSud
	 */
	But *getButSud()
	{
		return butSud;
	}

	/*!
	 * \brief Getteur
	 * Getteur de la liste des elements
	 */
	std::vector<Element*> getList()
	{
		return list;
	}

	/*!
	 * \brief Getteur
	 * Getteur du yStart
	 */
	int getYStart()const
	{
		return yStart;
	}

	/*!
	 * \brief Setteur
	 * Setteur du yStart
	 * \param ystart : la position initial
	 */
	void setYStart(const int &ystart)
	{
		this->yStart = ystart;
	}
};

#endif