#pragma once
#include "elementhaptique.h"
class DebutPartie :
	public ElementHaptique
{
public:
	DebutPartie();
	virtual ~DebutPartie();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

