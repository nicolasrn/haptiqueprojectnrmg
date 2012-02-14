/*!
 * \file Raquette.h
 * Fichier concernant le modele de la Raquette
 */

#pragma once

#ifndef __RAQUETTE__
#define __RAQUETTE__

#include "Element.h"

/*!
 * \brief Représente le modele de la raquette
 */
class Raquette : public Element
{
private:
	int idJoueur; /*!< un identifiant pour la distinction des raquettes */
	double vecteurDirecteurX; /*!< vecteur directeur sur x */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur du modele
	 * \param x : l'abscisse
	 * \param y : l'ordonnées
	 * \param idJoueur : identifiant qui sert juste a attribuer une couleur différente aux raquettes entre 0 et 255
	 */
	Raquette(const double &x, const int &y, const int &idJoueur);
	
	/*!
	 * \brief Destructeur
	 * Destructeur 
	 */
	virtual ~Raquette();
	
	/*!
	 * \brief Getteur de idJoueur
	 * Getteur de idJoueur 
	 */
	int getIdJoueur()const;
	
	/*!
	 * \brief Setteur de idJoueur
	 * Setteur de idJoueur
	 * \param idJoueur : un id
	 */
	void setIdJoueur(const int &idJoueur);

	/*!
	 * \brief Permet de deplacer la raquette en (x, y)
	 * Permet de deplacer la raquette
	 * \param x : l'abscisse
	 * \param y : l'ordonnées
	 */
	void deplacer(const double &x, const double &y);
	
	/*!
	 * \brief Permet de deplacer la raquette
	 * Permet de deplacer la raquette suivant vecteurDirecteurX
	 */
	void deplacer();

	/*!
	 * \brief Setter du vecteur directeur de X
	 * \param vx : le vecteur
	 */
	void setVecteurX(const double &vx);
};

#endif