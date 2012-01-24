#include "GUIPalet.h"

GUIPalet::GUIPalet(Palet *palet) : palet(palet)
{
}

GUIPalet::~GUIPalet(void)
{
}

void GUIPalet::dessiner(wxClientDC *dc)
{
	//dc->DrawEllipse(palet->getX(), palet->getY(), palet->getWidth(), palet->getHeight());
	wxColour rouge(255, 0, 0);

	wxBrush brush(rouge);
    dc->SetBrush(brush);

	dc->DrawCircle(palet->getX(), palet->getY(), palet->getWidth());
}