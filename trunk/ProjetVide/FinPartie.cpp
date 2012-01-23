#include "FinPartie.h"


FinPartie::FinPartie() : ElementHaptique(), Observer(), effets(NULL)
{
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		effets = mProjet->CreateEffect("fin");
		if (!effets)
		{
			delete effets;
			effets = NULL;
			wxMessageBox("erreur debut");
		}
	}
}


FinPartie::~FinPartie()
{
	
}

void FinPartie::recentrer()
{
}

void FinPartie::Start()
{
	effets->Start();
}

void FinPartie::Stop()
{
	effets->Stop();
}

void FinPartie::update(Observable *o, Data *data)
{
	DataFinPartie *d = dynamic_cast<DataFinPartie*>(data);
	if (d)
		this->Start();
}