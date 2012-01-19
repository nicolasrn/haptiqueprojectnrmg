#pragma once

#ifndef __GUITERRAINHAPTIQUE__
#define __GUITERRAINHAPTIQUE__

#include "guiterrain.h"
#include "GestionnaireSouris.h"

class GUITerrainHaptique : public GUITerrain
{
private:
	CImmEnclosure* mEnclos;
	CImmTexture* mTexture;

	wxPoint mCentreEnclosRelatif;

public:
	GUITerrainHaptique(wxWindow *parent, Terrain *terrain);
	virtual ~GUITerrainHaptique();
	
	CImmEnclosure *getEnclos();
	wxPoint& getCentreEnclosRelatif();
};

#endif