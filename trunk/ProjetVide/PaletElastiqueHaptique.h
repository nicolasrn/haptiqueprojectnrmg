#pragma once

#ifndef __PALETELASTIQUE__
#define __PALETELASTIQUE__

#include "PaletHaptique.h"

class PaletElastiqueHaptique : public PaletHaptique
{
public:
	PaletElastiqueHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~PaletElastiqueHaptique();
	
	virtual void recentrer();

	virtual void Start();

	virtual void Stop();

	virtual void update(Observable *o, Data *data);
};

#endif