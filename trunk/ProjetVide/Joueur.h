#pragma once

#ifndef __JOUEUR__
#define __JOUEUR__

#include "Observer.h"
#include <wx/msgdlg.h>

/*!
 * \brief Classe designant un joueur
 * Classe designant un joueur
 */
class Joueur : public Observable
{
private:
	unsigned int score; /*!< Represente le score du joueur */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	Joueur() : score(0)
	{
	}
	
	/*!
	 * \brief Incrementation du score
	 * Incrementation du score par defaut de 1
	 * \param v : la valeur a ajouter par defaut 1
	 */
	void incrementScore(const unsigned int &v = 1)
	{
		score += v;
		this->setChanged();
		this->notifyObservers(Data(score));
	}

	/*!
	 * \brief Getteur score
	 * Getteur score
	 */
	int getScore()const
	{
		return score;
	}
	
	/*!
	 * \brief Setteur score
	 * Setteur score
	 */
	void setScore(const unsigned int &v)
	{
		score = v;
	}
};

class JoueurHuman : public Joueur
{
public:
	JoueurHuman() : Joueur()
	{
	}
};

class JoueurIA : public Joueur
{
public:
	JoueurIA() : Joueur()
	{
	}
};

#endif