/*!
 * \file PaletElastiqueHaptique.h
 * fichier implémentant le palet elastique haptique
 */

#pragma once

#ifndef __PALETELASTIQUE__
#define __PALETELASTIQUE__

#include "PaletHaptique.h"
#include "GestionnaireSouris.h"

/*!
 * \brief Classe permettant la gestion du palet elastique
 * Classe permettant la gestion du palet elastique
 */
class PaletElastiqueHaptique : public PaletHaptique
{
private:
	CImmSpring *ressort;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param fenetre : l'interface du terrain
	 * \param terrain : le modele
	 */
	PaletElastiqueHaptique(GUITerrain *fenetre, Terrain *terrain);
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~PaletElastiqueHaptique();
	
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
	 * \brief Permet la mise a jour
	 * Permet la mise a jour via le notifyObservers
	 * \param o : l'observable
	 * \param data : la donnée a transmettre
	 */
	virtual void update(Observable *o, Data *data);
};

#endif