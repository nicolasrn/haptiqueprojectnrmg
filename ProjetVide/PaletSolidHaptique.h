/*!
 * \file PaletSolidElastique.h
 * fichier implémentant le palet solid haptique
 */

#pragma once

#ifndef __PALETSOLID__
#define __PALETSOLID__

#include <IFC.h>

#include "ElementHaptique.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"
#include "GUITerrain.h"
#include "Observer.h"
#include "PaletHaptique.h"

/*!
 * \brief Classe permettant la gestion du palet solid
 * Classe permettant la gestion du palet solid
 */
class PaletSolidHaptique : public PaletHaptique
{
private:
	CImmRamp *force;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	PaletSolidHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~PaletSolidHaptique();
	
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

	/*!
	 * \brief Permet de positionner le centre relatif
	 * Permet de positionner le centre relatif
	 * \param x : l'abscisse
	 * \param y : l'ordonnée
	 */
	virtual void setCentreRelatif(const int &x, const int &y);
	
	/*!
	 * \brief Permet la mise a jour
	 * Permet la mise a jour via le notifyObservers
	 * \param o : l'observable
	 * \param data : la donnée a transmettre
	 */
	virtual void update(Observable *o, Data *data);
};

#endif