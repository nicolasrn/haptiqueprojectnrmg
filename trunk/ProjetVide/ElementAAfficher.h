/*!
 * \file ElementAAfficher.h
 * Fichier d'interface permettant l'affichage d'element
 */

#pragma once

#ifndef __EltAAficher__
#define __EltAAficher__

#include <wx/dcclient.h>

/*!
 * \brief Permet de surcharger une methode d'affichage
 * Permet de surcharger une methode d'affichage
 */
class ElementAAfficher
{
public:
	/*!
	 * \brief Permet pour dessiner
	 * Permet de dessiner, méthode abstraite
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	virtual void dessiner(wxClientDC *dc) = 0;
};

#endif