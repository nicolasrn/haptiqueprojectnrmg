#pragma once

#ifndef __GUIPALETHAPTIQUE__
#define __GUIPALETHAPTIQUE__

#include <IFC.h>

#include "ElementHaptique.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"
#include "GUITerrain.h"
#include "Observer.h"

class PaletSolidHaptique : public ElementHaptique, public Observer
{
private:
	Terrain *terrain;
	GUITerrain *fenetre;

	//wxPoint mCentreEnclosRelatif;
	//CImmEllipse *mEnclos;

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