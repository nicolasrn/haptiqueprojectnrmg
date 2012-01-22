/*!
 * \file ElementHaptique.h
 * sert a identifier les elements haptiques
 */
#ifndef __ELEMENT_HAPTIQUE__
#define __ELEMENT_HAPTIQUE__

/*!
 * Classe representant les elements haptiques
 */
class ElementHaptique 
{
protected:
	bool debut;

public:
	ElementHaptique() : debut(false)
	{
	}

	bool getDebut()const
	{
		return debut;
	}

	void setDebut(const bool &b)
	{
		this->debut = b;
	}

	/*!
	 * la methode permettant de recentrer les effets lors de deplacements de fenetre
	 */
	virtual void recentrer() = 0;

	virtual void Start() = 0;

	virtual void Stop() = 0;

	virtual void setCentreRelatif(const int &x, const int &y) {}
};

#endif