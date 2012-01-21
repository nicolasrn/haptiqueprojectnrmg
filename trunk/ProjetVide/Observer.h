/*!
 * \file Observer.h
 * Implementation du pattern observer
 */
#ifndef __OBSERVER__
#define __OBSERVER__

#pragma once

#include <iostream>
#include <set>

class Observer;
class Observable;

struct Data
{
	/*unsigned int score;
	
	Data(const unsigned int &score) : score(score)
	{
	}*/
};

struct DataScore : public Data
{
	unsigned int score;
	
	DataScore(const unsigned int &score) : score(score)
	{
	}
};

struct DataCoordonnee : public Data
{
	unsigned int x, y;
	int vx, vy;

	DataCoordonnee(const unsigned int &x, const unsigned int &y, const int &vx, const int &vy) : x(x), y(y), vx(vx), vy(vy)
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
	std::set<Observer*> list;
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
	void notifyObservers(Data *data);
};

#endif