/*!
 * \file ButHaptique.h
 * Fichier contenant le l'haptique du but
 */

#pragma once

#ifndef __BUT_HAPTIQUE__
#define __BUT_HAPTIQUE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Observer.h"

/*!
 * \brief Classe permettant la getion du but haptique
 * Classe permettant la getion du but haptique
 */
class ButHaptique : public ElementHaptique, public Observer
{
private:
	CImmPeriodic *period;/*!< l'objet permettant de mettre en oeuvre l'haptique*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	ButHaptique();
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~ButHaptique();
	
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
	 * \brief Permet de faire la mise a jour
	 * Permet de faire la mise a jour lors du notifyObservers
	 * \param o : l'observable
	 * \param data : la donnée a transmettre
	 */
	virtual void update(Observable *o, Data *data);
};

#endif