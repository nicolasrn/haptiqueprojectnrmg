#pragma once

#ifndef __PALETHAPTIQUE__
#define __PALETHAPTIQUE__

#include "ElementHaptique.h"
#include "PaletHaptique.h"
#include "Observer.h"
#include "Terrain.h"
#include "GUITerrain.h"

class PaletHaptique : public ElementHaptique, public Observer
{
protected:
	GUITerrain *fenetre;
	Terrain *terrain;

public:
	PaletHaptique(GUITerrain *fenetre, Terrain *terrain);
	virtual ~PaletHaptique();
};

#endif