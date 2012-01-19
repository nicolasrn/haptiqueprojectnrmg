#include "GestionnaireSouris.h"

GestionnaireSouris *GestionnaireSouris::gestionnaire = NULL;

GestionnaireSouris::GestionnaireSouris(HINSTANCE h, WXWidget w)
{
	mSouris = new CImmMouse;
	if (!mSouris->Initialize(h, w))
	{
		delete mSouris;
		mSouris = NULL;
		throw std::exception("echec de l'initialisation de la souris");
	}
}

GestionnaireSouris::~GestionnaireSouris()
{
	if (mSouris != NULL)
		delete mSouris;
	mSouris = NULL;
}

GestionnaireSouris* GestionnaireSouris::getInstance(HINSTANCE h, WXWidget w)
{
	if (gestionnaire == NULL)
		gestionnaire = new GestionnaireSouris(h, w);
	return gestionnaire;
}

GestionnaireSouris* GestionnaireSouris::getInstance()
{
	return gestionnaire;
}

CImmMouse* GestionnaireSouris::getSouris()
{
	return this->mSouris;
}