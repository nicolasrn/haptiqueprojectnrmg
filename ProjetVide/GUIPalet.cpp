#include "GUIPalet.h"

GUIPalet::GUIPalet(Palet *palet) : Observer(), palet(palet), heurter(false)
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

	if (!heurter)
		dc->DrawCircle(palet->getX(), palet->getY(), palet->getWidth());
	else
		dc->DrawEllipse(palet->getX()-palet->getWidth()/2, palet->getY()-palet->getHeight()/2, palet->getWidth(), palet->getHeight()*0.77);

	heurter = false;
}

void GUIPalet::update(Observable *o, Data *data)
{
	heurter = true;
}