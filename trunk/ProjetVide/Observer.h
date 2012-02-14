/*!
 * \file Observer.h
 * Implementation du pattern observer
 */
#ifndef __OBSERVER__
#define __OBSERVER__

#pragma once

#include <iostream>
#include <vector>

class Observer;
class Observable;

/*!
 * \brief classe permettant de faire la liason de données entre l'observer et l'observable
 */
class Data
{
public:
	/*!
	 * \brief Destructeur virtuel
	 * Destructeur virtuel
	 */
	virtual ~Data()
	{
	}
	/*unsigned int score;
	
	Data(const unsigned int &score) : score(score)
	{
	}*/
};

/*!
 * \brief classe permettant de faire la liason de données entre l'observer et l'observable
 */
class DataScore : public Data
{
public:
	unsigned int score;/*!< Le score joueur */
	
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param score : le score a transmettre
	 */
	DataScore(const unsigned int &score) : Data(), score(score)
	{
	}
	
	/*!
	 * \brief Destructeur virtuel
	 * Destructeur virtuel
	 */
	virtual ~DataScore()
	{
	}
};

/*!
 * \brief classe permettant de faire la liason de données entre l'observer et l'observable
 */
class DataCoordonnee : public Data
{
public:
	unsigned int x/*!< coordonnées x */, y;/*!< coordonnées y */
	int vx/*!< vecteur de deplacement vx */, vy;/*!< vecteur de deplacement vy */
	
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param x : abscisse
	 * \param y : ordonnée
	 * \param vx : vecteur de l'abscisse
	 * \param vy : vecteur de l'ordonnée
	 */
	DataCoordonnee(const unsigned int &x, const unsigned int &y, const int &vx, const int &vy) : 
		Data(), x(x), y(y), vx(vx), vy(vy)
	{
	}
		
	/*!
	 * \brief Destructeur virtuel
	 * Destructeur virtuel
	 */
	virtual ~DataCoordonnee()
	{
	}
};

/*!
 * \brief classe permettant de faire la liason de données entre l'observer et l'observable
 */
class DataBut : public Data
{
public:
	/*!
	 * \brief Destructeur virtuel
	 * Destructeur virtuel
	 */
	virtual ~DataBut()
	{
	}
};

/*!
 * \brief classe permettant de faire la liason de données entre l'observer et l'observable
 */
class DataFinPartie : public Data
{
public:
	/*!
	 * \brief Destructeur virtuel
	 * Destructeur virtuel
	 */
	virtual ~DataFinPartie()
	{
	}
};

/*!
 * \brief Implementation du pattern observer
 * Implementation du pattern observer
 */
class Observer
{
public:
	/*!
	 * \brief Methode de mise a jour
	 * Methode appele lors du notifyObservers
	 */
	virtual void update(Observable *o, Data *data) = 0;
};

/*!
 * \brief Implementation du pattern observer observable
 * Implementation du pattern observer observable
 */
class Observable
{
private:
	/*!< Liste contenant les observers */
	std::vector<Observer*> list;
	bool changed;

public:
	/*!
	 * Constructeur
	 */
	Observable();

	/*!
	 * \brief Ajoute un observer
	 * Ajoute un observer
	 * \param o : l'observer
	 */
	void addObserver(Observer *o);
	
	/*!
	 * \brief Retourne vrai si des modifications ont ete note
	 * Retourne vrai si des modifications ont ete note
	 * \return bool
	 */
	bool hasChanged()const;
	
	/*!
	 * \brief Met a vrai les changements
	 * Met a vrai les changements
	 */
	void setChanged();
	
	/*!
	 * \brief Annule les modifications
	 * Annule les modifications
	 */
	void clearChanged();
	
	/*!
	 * \brief Supprimer l'observer
	 * Supprimer l'observer
	 */
	void deleteObserver(Observer *o);
	
	/*!
	 * \brief Supprimer la liste des observers
	 *
	 */
	void deleteObservers();
	
	/*!
	 * \brief Notify les observers
	 * Notify les observers
	 * \param data : n'importe quel objet
	 */
	void notifyObservers(Data *data = NULL);
};

#endif