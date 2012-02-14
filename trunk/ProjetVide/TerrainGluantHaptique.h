/*!
 * \file TerrainGluantHaptique.h
 * fichier implémentant le TerrainGluantHaptique
 */

#pragma once

#ifndef __TERRAINGLUANT__
#define __TERRAINGLUANT__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "TerrainHaptique.h"

/*!
 * \brief Classe permettant la gestion du TerrainGluantHaptique
 * Classe permettant la gestion du TerrainGluantHaptique
 */
class TerrainGluantHaptique : public TerrainHaptique
{
private:
	CImmTexture *mTexture;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	TerrainGluantHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~TerrainGluantHaptique();

};

#endif