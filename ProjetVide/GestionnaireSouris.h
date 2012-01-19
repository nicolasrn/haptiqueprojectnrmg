#pragma once

#ifndef __GESTIONNAIRESOURIS__
#define __GESTIONNAIRESOURIS__

#include <iostream>
#include <IFC.h>
#include <wx/wxprec.h>
	
class GestionnaireSouris
{
private:
	static GestionnaireSouris *gestionnaire;

	CImmMouse *mSouris;
	
	GestionnaireSouris(HINSTANCE h, WXWidget w);

public:
	static bool ActivationGestionnaire;

	virtual ~GestionnaireSouris();
	static GestionnaireSouris* getInstance(HINSTANCE h, WXWidget w);
	static GestionnaireSouris* getInstance();

	CImmMouse* getSouris();
};

#endif