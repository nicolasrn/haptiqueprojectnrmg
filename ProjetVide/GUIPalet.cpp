#include "GUIPalet.h"

GUIPalet::GUIPalet(Palet *palet) : Observer(), palet(palet), heurter(false), ref(0), delai(0)
{
	delai = 2;
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
	{
		if (ref == 0)
			ref = time(&ref);

		time_t ref2;
		time(&ref2);
		time_t tmp = delai + ref - ref2;
		if (tmp > 0)
			dc->DrawEllipse(palet->getX()-palet->getWidth()/2, palet->getY()-palet->getHeight()/2, palet->getWidth(), palet->getHeight()*0.77);
		else
		{
			heurter = false; 
			ref = 0;
		}
	}
}

void GUIPalet::update(Observable *o, Data *data)
{
	heurter = true;
}