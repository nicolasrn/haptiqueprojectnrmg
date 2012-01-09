/*!
 * \file GUIRaquette.h
 * Fichier concernant la vue de la raquette
 */
#pragma once

#ifndef __GUIRAQUETTE__
#define __GUIRAQUETTE__

#include <wx/dcclient.h>

#include "elementaafficher.h"
#include "Raquette.h"

/*!
 * \brief Représente la vue de la raquette
 */
class GUIRaquette :	public ElementAAfficher
{
private:
	Raquette *raquette;/*!< Le modele représentant la raquette */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de la vue raquette
	 * \param raquette : le modele de la vue
	 */
	GUIRaquette(Raquette *raquette);

	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	~GUIRaquette();
	
	/*!
	 * \brief Surcharge pour dessiner
	 * Surcharge pour dessiner
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	void dessiner(wxClientDC *dc);
};

#endif