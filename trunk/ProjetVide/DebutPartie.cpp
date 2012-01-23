#include "DebutPartie.h"


DebutPartie::DebutPartie() : ElementHaptique(), effets(NULL)
{
	this->debut = true;
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		this->effets = mProjet->CreateEffect("debut");
		if (!effets)
		{
			delete this->effets;
			this->effets = NULL;
			wxMessageBox("erreur debut");
		}
	}
}

DebutPartie::~DebutPartie()
{
}

void DebutPartie::recentrer()
{
}

void DebutPartie::Start()
{
	effets->Start();
}

void DebutPartie::Stop()
{
	effets->Stop();
}