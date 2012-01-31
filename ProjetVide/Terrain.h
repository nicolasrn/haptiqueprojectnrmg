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
#include <ctime>

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
	double yStart; /*!< Position a partir de laquelle le terrain commence sur la GUI*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param width : l'abscisse
	 * \param height : l'ordonnées
	 */
	Terrain(const double &width, const double &height);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	virtual ~Terrain();

	/*!
	 * \brief Getteur
	 * Getteur de la raquette du joueur
	 */
	Raquette *getHuman();
	
	/*!
	 * \brief Getteur
	 * Getteur de la raquette de l'ordinateur
	 */
	Raquette *getIa();
	
	/*!
	 * \brief Getteur
	 * Getteur du palet
	 */
	Palet *getPalet();
	
	/*!
	 * \brief Getteur
	 * Getteur du butNord
	 */
	But *getButNord();
	
	/*!
	 * \brief Getteur
	 * Getteur du butSud
	 */
	But *getButSud();

	/*!
	 * \brief Getteur
	 * Getteur de la liste des elements
	 */
	std::vector<Element*> getList();

	/*!
	 * \brief Getteur
	 * Getteur du yStart
	 */
	double getYStart()const;

	/*!
	 * \brief Setteur
	 * Setteur du yStart
	 * \param ystart : la position initial
	 */
	void setYStart(const double &ystart);
	
	/*!
	 * \brief Setteur de la vitesse induite par le terrain
	 * Setteur du vecteur de deplacement sur x
	 */
	virtual void setVitesseTerrain(const double &vitesseTerrain);
};

#endif