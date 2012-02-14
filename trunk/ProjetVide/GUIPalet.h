/*!
 * \file GUIPalet.h
 * Fichier concernant la vue du palet
 */
#pragma once

#ifndef __GUIPALET__
#define __GUIPALET__

#include <wx/dcclient.h>

#include "elementaafficher.h"
#include "Palet.h"
#include "Observer.h"

/*!
 * \brief repr�sente la vue du palet
 */
class GUIPalet : public ElementAAfficher, public Observer
{
private:
	Palet *palet; /*!< Le modele repr�sentant le palet */
	bool heurter;/*!< pour savoir si il y a eu un coup */

	time_t ref;/*!< temps de reference */
	time_t delai;/*!< delai d'attente */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de la vue palet
	 * \param palet : le modele de la vue
	 */
	GUIPalet(Palet *palet);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	virtual ~GUIPalet();
	
	/*!
	 * \brief Surcharge pour dessiner
	 * Surcharge pour dessiner
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	void dessiner(wxClientDC *dc);
	
	/*!
	 * \brief M�thode de mise a jour
	 * M�thode de mise a jour via notifyObservers
	 * \param o : l'observable
	 * \param data : la donn�e a transmettre
	 */
	void update(Observable *o, Data *data);
};

#endif