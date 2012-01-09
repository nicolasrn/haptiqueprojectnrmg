#include "GUIRaquette.h"


GUIRaquette::GUIRaquette(Raquette *raquette) : raquette(raquette)
{
}


GUIRaquette::~GUIRaquette()
{
}

void GUIRaquette::dessiner(wxClientDC *dc)
{
	//dc->DrawLine(raquette->getX()-10, raquette->getY(), raquette->getX()+10, raquette->getY()); 
	dc->DrawCircle(raquette->getX(), raquette->getY(), raquette->getHeight());
	//dc->DrawEllipse(raquette->getX(), raquette->getY(), raquette->getHeight(), raquette->getWidth());
}
