/*!
 * \file PaletElastique.h
 * fichier implémentant le palet haptique
 */

#pragma once

#ifndef __PALETHAPTIQUE__
#define __PALETHAPTIQUE__

#include "ElementHaptique.h"
#include "PaletHaptique.h"
#include "Observer.h"
#include "Terrain.h"
#include "GUITerrain.h"

/*!
 * \brief Classe permettant la gestion du palet 
 * Classe permettant la gestion du palet 
 */
class PaletHaptique : public ElementHaptique, public Observer
{
protected:
	GUITerrain *fenetre;/*!< la vue */
	Terrain *terrain;/*!< le terrain*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	PaletHaptique(GUITerrain *fenetre, Terrain *terrain);

	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~PaletHaptique();
};

#endif