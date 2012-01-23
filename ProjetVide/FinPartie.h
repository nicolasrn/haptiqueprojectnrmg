#pragma once

#ifndef __FIN_PARTIE__
#define __FIN_PARTIE__

#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Observer.h"

class FinPartie : public ElementHaptique, public Observer
{
private:
	CImmCompoundEffect *effets;

public:
	FinPartie();
	virtual ~FinPartie();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();

	virtual void update(Observable *o, Data *data);
};

#endif