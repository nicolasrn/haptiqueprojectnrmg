/*!
 * \file DebutPartie.h
 * Fichier contenant le debut haptique
 */
#pragma once

#ifndef __DEBUT_PARTIE__
#define __DEBUT_PARTIE__

#include "ElementHaptique.h"
#include "GestionnaireSouris.h"

/*!
 * \brief Classe permettant la getion du debut de partie haptique
 * Classe permettant la getion du debut de partie haptique
 */
class DebutPartie :	public ElementHaptique
{
private:
	CImmCompoundEffect *effets;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	DebutPartie();

	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~DebutPartie();
	
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