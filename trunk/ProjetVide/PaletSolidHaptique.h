#pragma once

#ifndef __PALETSOLID__
#define __PALETSOLID__

#include <IFC.h>

#include "ElementHaptique.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"
#include "GUITerrain.h"
#include "Observer.h"
#include "PaletHaptique.h"

class PaletSolidHaptique : public PaletHaptique
{
private:
	CImmRamp *force;

public:
	PaletSolidHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~PaletSolidHaptique();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();

	virtual void setCentreRelatif(const int &x, const int &y);

	virtual void update(Observable *o, Data *data);
};

#endif