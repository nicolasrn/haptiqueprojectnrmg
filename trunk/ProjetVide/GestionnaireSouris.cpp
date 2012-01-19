#include "GestionnaireSouris.h"

GestionnaireSouris *GestionnaireSouris::gestionnaire = NULL;
bool GestionnaireSouris::ActivationGestionnaire = false;

GestionnaireSouris::GestionnaireSouris(HINSTANCE h, WXWidget w)
{
	mSouris = new CImmMouse;
	ActivationGestionnaire = true;
	if (!mSouris->Initialize(h, w))
	{
		delete mSouris;
		mSouris = NULL;
		ActivationGestionnaire = false;
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
	if (ActivationGestionnaire)
		return gestionnaire;
	else 
		return NULL;
}

CImmMouse* GestionnaireSouris::getSouris()
{
	return this->mSouris;
}