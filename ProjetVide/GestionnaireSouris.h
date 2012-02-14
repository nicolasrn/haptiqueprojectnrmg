/*!
 * \file GestionnaireSouris.h
 * fichier implémentant la souris haptique
 */

#pragma once

#ifndef __GESTIONNAIRESOURIS__
#define __GESTIONNAIRESOURIS__

#include <iostream>
#include <IFC.h>
#include <wx/wxprec.h>


/*!
 * \brief GestionnaireSouris de la fenetre
 * Classe qui permet la singletonite sur la souris
 */
class GestionnaireSouris
{
private:
	static GestionnaireSouris *gestionnaire;/*!< variable pour le singleton*/

	CImmMouse *mSouris;/*!< la variable a protéger du duplicat*/
	
	/*!
	 * \brief constructeur privé
	 * \param h : le hinstance
	 * \param w : le WXWidget
	 */
	GestionnaireSouris(HINSTANCE h, WXWidget w);

public:
	static bool ActivationGestionnaire;/*!< variable indicant si la souris est activé*/

	/*!
	 * destructeur virtuel
	 */
	virtual ~GestionnaireSouris();

	/*!
	 * \brief getteur du singleton
	 * \param h : le hinstance
	 * \param w : le WXWidget
	 * \return GestionnaireSouris*
	 */
	static GestionnaireSouris* getInstance(HINSTANCE h, WXWidget w);
	
	/*!
	 * \brief getteur du singleton
	 * \return GestionnaireSouris*
	 */
	static GestionnaireSouris* getInstance();
	
	/*!
	 * \brief getteur de la souris
	 * \return CImmMouse
	 */
	CImmMouse* getSouris();
};

#endif