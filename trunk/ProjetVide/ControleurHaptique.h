#ifndef __CONTROLEUR_HAPTIQUE__
#define __CONTROLEUR_HAPTIQUE__

#include "ElementHaptique.h"

class ControleurHaptique
{
private:
	ElementHaptique *palet;
	ElementHaptique *terrain;

public:
	ControleurHaptique();
	~ControleurHaptique();
};

#endif