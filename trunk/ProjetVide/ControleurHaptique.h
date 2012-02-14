/*!
 * \file ControleurHaptique.h
 * Fichier contenant le Controleur haptique de l'application
 */

#ifndef __CONTROLEUR_HAPTIQUE__
#define __CONTROLEUR_HAPTIQUE__

#include <iostream>
#include <vector>

#include "ElementHaptique.h"

/*!
 * \brief ControleurHaptique de l'application
 * ControleurHaptique de l'application
 */
class ControleurHaptique : public ElementHaptique
{
private:
	std::vector<ElementHaptique*> list;/*!< list des éléments*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du controleur
	 */
	ControleurHaptique();
	
	/*!
	 * \brief destructeur
	 * destructeur du controleur
	 */
	~ControleurHaptique();
	
	/*!
	 * \brief Permet de rajouter un element
	 * Permet de rajouter un element
	 * \param elt : le temps
	 */
	void add(ElementHaptique *elt);
	
	/*!
	 * \brief Permet de supprimer tous les éléments
	 * Permet de supprimer tous les éléments
	 */
	void removeAll();
	
	/*!
	 * \brief Permet de lancer le recentrage si besoin deprecié
	 * Permet de lancer le recentrage si besoin
	 */
	virtual void recentrer();
	
	/*!
	 * \brief Permet de lancer l'haptique
	 * Permet de lancer l'haptique
	 */
	virtual void Start();
	
	/*!
	 * \brief Permet de stopper l'haptique
	 * Permet de stopper l'haptique
	 */
	virtual void Stop();
	
	/*!
	 * \brief Permet de placer le centre relatif si besoin
	 * Permet de placer le centre relatif si besoin
	 * \param x : l'abscisse
	 * \param y : l'ordonnée
	 */
	virtual void setCentreRelatif(const int &x, const int &y);

};

#endif