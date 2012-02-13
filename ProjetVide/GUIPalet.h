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
 * \brief représente la vue du palet
 */
class GUIPalet : public ElementAAfficher, public Observer
{
private:
	Palet *palet; /*!< Le modele représentant le palet */
	bool heurter;

	time_t ref;
	time_t delai;

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

	void update(Observable *o, Data *data);
};

#endif