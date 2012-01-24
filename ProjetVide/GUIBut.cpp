#include "GUIBut.h"

GUIBut::GUIBut(But *but) : ElementAAfficher(), but(but)
{
}

GUIBut::~GUIBut(void)
{
}

void GUIBut::dessiner(wxClientDC *dc)
{
	wxColour bleu(100,100,255);

    wxPen pen(bleu, 5, wxSOLID);
    dc->SetPen(pen);
	
	dc->DrawLine(but->getX(), but->getY(), but->getX() + but->getWidth(), but->getY()); 
}