#pragma once

#ifndef __DEBUT_PARTIE__
#define __DEBUT_PARTIE__

#include "ElementHaptique.h"

class DebutPartie :	public ElementHaptique
{
public:
	DebutPartie();
	virtual ~DebutPartie();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

#endif