#include "GUIPalet.h"


GUIPalet::GUIPalet(Palet *palet) : palet(palet)
{
}


GUIPalet::~GUIPalet(void)
{
}

void GUIPalet::dessiner(wxClientDC *dc)
{
	dc->DrawCircle(palet->getX(), palet->getY(), 10);
}