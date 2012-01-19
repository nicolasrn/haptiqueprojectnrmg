/*!
 * \file Controleur.h
 * Fichier contenant le Controleur de l'application
 */

#pragma once

#ifndef __CONTROLLEUR__
#define __CONTROLLEUR__

#include <iostream>
#include <exception>
#include <wx/object.h>
#include <wx/dcclient.h>
#include <wx/timer.h>
#include <wx/event.h>

#include "Element.h"
#include "Palet.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "GestionCollision.h"
#include "GestionnaireSouris.h"
#include "Joueur.h"
#include "PaletHaptique.h"

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

	Joueur *humainPlayer, *IaPlayer;/*!< Le modele joueur */

	static bool marque;/*!< Sert de verification */

public:
	PaletHaptique *paletHaptique;

	/*!
	 * \brief Constructeur
	 * Constructeur du controleur
	 */
	Controleur(Terrain *terrain, GUITerrain *guiTerrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~Controleur();

	/*!
	 * \brief Permet de lancer le timer
	 * Permet de lancer le timer
	 * \param int : le temps
	 */
	void start(int ms = 0);
	
	/*!
	 * \brief Permet de stopper le timer
	 * Permet de stopper le timer
	 */
	void stop();

	/*!
	 * \brief Remet a zero
	 * Remet a zero
	 */
	void reset();

	/*!
	 * \brief Permet de repeter les actions du controleur toutes les n secondes
	 * Permet de repeter les actions du controleur toutes les n secondes
	 * \param event : l'evenement
	 */
	void compute(wxTimerEvent& WXUNUSED(event));

	DECLARE_EVENT_TABLE();
};

#endif