/*!
 * \file FinPartie.h
 * Fichier contenant le l'haptique de fin
 */

#pragma once

#ifndef __FIN_PARTIE__
#define __FIN_PARTIE__

#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Observer.h"

/*!
 * \brief Classe permettant la getion du fin de partie haptique
 * Classe permettant la getion du fin de partie haptique
 */
class FinPartie : public ElementHaptique, public Observer
{
private:
	CImmCompoundEffect *effets;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	FinPartie();

	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~FinPartie();
	
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