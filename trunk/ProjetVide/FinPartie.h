#pragma once
#include "elementhaptique.h"
class FinPartie :
	public ElementHaptique
{
public:
	FinPartie();
	virtual ~FinPartie();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

