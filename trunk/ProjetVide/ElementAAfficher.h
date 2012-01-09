#pragma once

#ifndef __EltAAficher__
#define __EltAAficher__

#include <wx/dcclient.h>

class ElementAAfficher
{
public:
	virtual void dessiner(wxClientDC *dc) = 0;
};

#endif