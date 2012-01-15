/*!
 * \file but.h
 * Fichier metier representant un but
 */

#pragma once

#ifndef __GUIBUT__
#define __GUIBUT__

#include "elementaafficher.h"
#include "But.h"

/*!
 * \brief Classe vue du But
 * Classe vue du But
 */
class GUIBut : public ElementAAfficher
{
private:
	But *but; /*!< Donnee metier du but */

public:
	/*!
	 * \brief Constructeur de la classe
	 * Constructeur de la classe
	 * \param but : l'objet menu
	 */
	GUIBut(But *but);

	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~GUIBut();
	
	/*!
	 * \brief Permet pour dessiner
	 * Permet de dessiner, méthode abstraite
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	void dessiner(wxClientDC *dc);
};

#endif