#pragma once

#ifndef __GUIPALETHAPTIQUE__
#define __GUIPALETHAPTIQUE__

#include <IFC.h>

#include "ElementHaptique.h"
#include "Terrain.h"
#include "GestionnaireSouris.h"
#include "GUITerrain.h"

class PaletHaptique : public ElementHaptique
{
private:
	Terrain *terrain;
	GUITerrain *fenetre;

	wxPoint mCentreEnclosRelatif;
	CImmEllipse *mEnclos;

public:
	PaletHaptique(GUITerrain *fenetre, Terrain *terrain);

	virtual ~PaletHaptique();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();

	virtual void setCentreRelatif(const int &x, const int &y);
};

#endif