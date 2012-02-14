/*!
 * \file TerrainNormalHaptique.h
 * fichier implémentant le TerrainNormalHaptique
 */
#pragma once

#ifndef __TERAINNORMALE__
#define __TERAINNORMALE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "TerrainHaptique.h"

/*!
 * \brief Classe permettant la gestion du TerrainNormalHaptique
 * Classe permettant la gestion du TerrainNormalHaptique
 */
class TerrainNormalHaptique : public TerrainHaptique
{
private:
	CImmFriction *mFriction;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	TerrainNormalHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~TerrainNormalHaptique();
	
};

#endif