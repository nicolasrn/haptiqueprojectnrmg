#pragma once
#include "elementhaptique.h"
class PaletElastiqueHaptique :
	public ElementHaptique
{
public:
	PaletElastiqueHaptique();
	virtual ~PaletElastiqueHaptique();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
};

