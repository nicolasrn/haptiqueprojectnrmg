/*!
 * \file TerrainHaptique.h
 * fichier implémentant le TerrainHaptique
 */
#pragma once

#ifndef __TERRAINHAPTIQUE__
#define __TERRAINHAPTIQUE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GUITerrain.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"

/*!
 * \brief Classe permettant la gestion du TerrainHaptique
 * Classe permettant la gestion du TerrainHaptique
 */
class TerrainHaptique : public ElementHaptique
{
protected:
	GUITerrain *fenetre;/*!< la vue */
	Terrain *terrain;/*!< le modele */

	wxPoint mCentreEnclosRelatif;/*!< le centre */
	CImmEnclosure *mEnclos;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	TerrainHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~TerrainHaptique();
	
	/*!
	 * \brief Permet de recentrer
	 * Permet de recentrer
	 */
	virtual void recentrer();
	
	/*!
	 * \brief Permet de declancher l'action
	 * Permet de declancher l'action
	 */
	virtual void Start();
	
	/*!
	 * \brief Permet de stopper l'action
	 * Permet de stopper l'action
	 */
	virtual void Stop();
};

#endif