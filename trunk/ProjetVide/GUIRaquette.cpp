#include "GUIRaquette.h"


GUIRaquette::GUIRaquette(Raquette *raquette) : raquette(raquette)
{
}


GUIRaquette::~GUIRaquette()
{
}

void GUIRaquette::dessiner(wxClientDC *dc)
{
	dc->DrawLine(raquette->getX()-10, raquette->getY(), raquette->getX()+10, raquette->getY()); 
}
