/*!
 * \file ElementHaptique.h
 * sert a identifier les elements haptiques
 */
#ifndef __ELEMENT_HAPTIQUE__
#define __ELEMENT_HAPTIQUE__

#include <IFC.h>

/*!
 * \brief Classe representant les elements haptiques
 * Classe representant les elements haptiques
 */
class ElementHaptique 
{
protected:
	bool debut;/*!< l'objet permettant d'indiquer si l'action doit être fait au début*/
	CImmProject *mProjet;/*!< l'objet permettant de mettre en oeuvre l'haptique si dans le projet*/

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 */
	ElementHaptique() : debut(false), mProjet(NULL)
	{
		mProjet = new CImmProject();
	}
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~ElementHaptique()
	{
		if (mProjet != NULL)
			delete mProjet;
		mProjet = NULL;
	}
	
	/*!
	 * \brief Getter du debut
	 * Getter du debut
	 * \return bool
	 */
	bool getDebut()const
	{
		return debut;
	}
	
	/*!
	 * \brief Setter du debut
	 * Setter du debut
	 * \param b : le boolean
	 */
	void setDebut(const bool &b)
	{
		this->debut = b;
	}

	/*!
	 * \brief La methode permettant de recentrer les effets lors de deplacements de fenetre
	 *  La methode permettant de recentrer les effets lors de deplacements de fenetre
	 */
	virtual void recentrer() = 0;
	
	/*!
	 * \brief Permet de lancer l'effet
	 * Permet de lancer l'effet
	 */
	virtual void Start() = 0;
	
	/*!
	 * \brief Permet de stopper l'effet
	 * Permet de stopper l'effet
	 */
	virtual void Stop() = 0;
	
	/*!
	 * \brief Permet le recentrage relatif
	 * Permet le recentrage relatif
	 * \param x : l'abscisse
	 * \param y : l'ordonnée
	 */
	virtual void setCentreRelatif(const int &x, const int &y) {}
};

#endif