#pragma once

#ifndef __GUIPALET__
#define __GUIPALET__

#include <wx/dcclient.h>

#include "elementaafficher.h"
#include "Palet.h"

class GUIPalet : public ElementAAfficher
{
private:
	Palet *palet;

public:
	GUIPalet(Palet *palet);
	~GUIPalet();

	void dessiner(wxClientDC *dc);
};

#endif