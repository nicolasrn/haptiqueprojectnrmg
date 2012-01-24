#include "GUIRaquette.h"

GUIRaquette::GUIRaquette(Raquette *raquette) : raquette(raquette)
{
}

GUIRaquette::~GUIRaquette()
{
}

void GUIRaquette::dessiner(wxClientDC *dc)
{
	wxColour blue(0, 0, raquette->getIdJoueur());

	wxBrush brush(blue);
    dc->SetBrush(brush);

	//dc->DrawLine(raquette->getX()-10, raquette->getY(), raquette->getX()+10, raquette->getY()); 
	dc->DrawCircle(raquette->getX(), raquette->getY(), raquette->getHeight());
	//dc->DrawEllipse(raquette->getX(), raquette->getY(), raquette->getHeight(), raquette->getWidth());
}
