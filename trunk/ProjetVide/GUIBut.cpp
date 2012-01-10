#include "GUIBut.h"


GUIBut::GUIBut(But *but) : ElementAAfficher(), but(but)
{
}

GUIBut::~GUIBut(void)
{
}

void GUIBut::dessiner(wxClientDC *dc)
{
	wxColour rouge(0,0,255);

    wxPen pen(rouge, 5, wxSOLID);
    dc->SetPen(pen);
	
	dc->DrawLine(but->getX(), but->getY(), but->getX() + but->getWidth(), but->getY()); 
}