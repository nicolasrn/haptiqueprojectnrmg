#pragma once

#ifndef __TERRAIN__
#define __TERRAIN__

#include <iostream>
#include <wx/panel.h>

#include "Raquette.h"
#include "Palet.h"

class Terrain
{
private:
	int width;
	int height;

	Raquette *human, *ia;
	Palet *palet;

public:
	Terrain(const int &width, const int &height);
	~Terrain();

	Raquette *getHuman()
	{
		return human;
	}

	Raquette *getIa()
	{
		return ia;
	}

	Palet *getPalet()
	{
		return palet;
	}
};

#endif