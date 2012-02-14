/*!
 * \file TerrainTresGlissantHaptique.h
 * fichier implémentant le TerrainTresGlissantHaptique
 */
#pragma once

#ifndef __TERRAINGLISSANT__
#define __TERRAINGLISSANT__

#include <IFC.h>
#include "TerrainHaptique.h"
#include "Terrain.h"
#include "GUITerrain.h"
#include "GestionnaireSouris.h"

/*!
 * \brief Classe permettant la gestion du TerrainTresGlissantHaptique
 * Classe permettant la gestion du TerrainTresGlissantHaptique
 */
class TerrainTresGlissantHaptique : public TerrainHaptique
{
public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	TerrainTresGlissantHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~TerrainTresGlissantHaptique();
	
};

#endif