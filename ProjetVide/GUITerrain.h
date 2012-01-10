/*!
 * \file GUITerrain.h
 * Fichier concernant la vue terrain
 */
#pragma once

#ifndef __GUITERRAIN__
#define __GUITERRAIN__

#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/stattext.h>

#include "ElementAAfficher.h"
#include "Terrain.h"
#include "GUIPalet.h"
#include "GUIRaquette.h"

/*!
 * \brief la vue terrain
 * Représente la vue du terrain et de ce qui dépend d'elle
 */
class GUITerrain : public wxPanel, ElementAAfficher
{
private:
	Terrain *terrain;/*!< Le modele terrain*/

	GUIRaquette *guiHuman, *guiIA; /*!< La vue raquette */
	GUIPalet *guiPalet; /*!< La vue du palet */
	wxStaticText *label; /*!< La vue du score */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de la vue terrain
	 * 
	 * \param parent : la vue parente
	 * \param terrain : modele du terrain
	 * \param id : l'id du composant
	 */
	GUITerrain(wxWindow* parent, Terrain *terrain, wxWindowID id = wxID_ANY);

	/*!
	 * \brief Destructeur
	 * Détruit les vues
	 */
	~GUITerrain();

	/*!
	 * \brief Surcharge pour dessiner
	 * Surcharge pour dessiner
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	void dessiner(wxClientDC *dc);
	
	/*!
	 * \brief Détecte les mouvements du joueur
	 * Détecte les mouvements du joueur afin de mettre a jour le modele 
	 * \param event : l'évenement
	 */
	void onSourisMove(wxMouseEvent& event);

	/*!
	 * \brief Getteur du label score
	 * Getteur du label score
	 * \return wxStaticText
	 */
	wxStaticText* getLabelScore()const
	{
		return label;
	}
	
	DECLARE_EVENT_TABLE();
};

#endif