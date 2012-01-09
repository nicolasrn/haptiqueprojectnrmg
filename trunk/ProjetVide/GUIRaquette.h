#pragma once

#ifndef __GUIRAQUETTE__
#define __GUIRAQUETTE__

#include <wx/dcclient.h>

#include "elementaafficher.h"
#include "Raquette.h"

class GUIRaquette :	public ElementAAfficher
{
private:
	Raquette *raquette;

public:
	GUIRaquette(Raquette *raquette);
	~GUIRaquette();

	void dessiner(wxClientDC *dc);
};

#endif