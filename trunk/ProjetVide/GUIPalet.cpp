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
	dc->DrawCircle(palet->getX(), palet->getY(), palet->getWidth());
}