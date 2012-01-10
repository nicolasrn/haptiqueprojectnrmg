/*!
 * \file Controleur.h
 * Fichier contenant le Controleur de l'application et le joueur
 */

#pragma once

#ifndef __CONTROLLEUR__
#define __CONTROLLEUR__

#include <iostream>
#include <wx/object.h>
#include <wx/dcclient.h>
#include <wx/timer.h>
#include <wx/event.h>

#include "Element.h"
#include "Palet.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "GestionCollision.h"

/*!
 * \brief Classe designant un joueur
 * Classe designant un joueur
 */
class Joueur
{
private:
	unsigned int score; /*!< Represente le score du joueur */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	Joueur() : score(0)
	{
	}
	
	/*!
	 * \brief Incrementation du score
	 * Incrementation du score par defaut de 1
	 * \param v : la valeur a ajouter par defaut 1
	 */
	void incrementScore(const unsigned int &v = 1)
	{
		score += v;
	}
};


/*!
 * \brief Controleur de l'application
 * Controleur de l'application
 */
class Controleur : public wxEvtHandler
{
private:
	Terrain *terrain;/*!< Pointeur vers le modele*/
	GUITerrain *guiTerrain;/*!< Pointeur vers la vue*/

	wxTimer *timer; /*!< Va servir de base au controleur */

	Joueur *humainPlayer, *IaPlayer;

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du controleur
	 */
	Controleur(Terrain *terrain, GUITerrain *guiTerrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	~Controleur();

	/*!
	 * \brief Permet de lancer le timer
	 * Permet de lancer le timer
	 * \param int : le temps
	 */
	void start(int ms);
	
	/*!
	 * \brief Permet de stopper le timer
	 * Permet de stopper le timer
	 */
	void stop();

	/*!
	 * \brief Permet de repeter les actions du controleur toutes les n secondes
	 * Permet de repeter les actions du controleur toutes les n secondes
	 * \param event : l'evenement
	 */
	void compute(wxTimerEvent& event);

	DECLARE_EVENT_TABLE();
};

#endif