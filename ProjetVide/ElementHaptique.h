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
public:
	/*!
	 * la methode permettant de recentrer les effets lors de deplacements de fenetre
	 */
	virtual void recentrer() = 0;

};

#endif