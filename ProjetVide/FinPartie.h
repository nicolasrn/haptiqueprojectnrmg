#pragma once

#ifndef __FIN_PARTIE__
#define __FIN_PARTIE__

#include "ElementHaptique.h"

class FinPartie : public ElementHaptique
{
public:
	FinPartie();
	virtual ~FinPartie();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

#endif