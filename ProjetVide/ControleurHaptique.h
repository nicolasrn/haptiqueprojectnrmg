#ifndef __CONTROLEUR_HAPTIQUE__
#define __CONTROLEUR_HAPTIQUE__

#include <iostream>
#include <vector>

#include "ElementHaptique.h"

class ControleurHaptique : public ElementHaptique
{
private:
	std::vector<ElementHaptique*> list;

public:
	ControleurHaptique();

	~ControleurHaptique();

	ElementHaptique* add(ElementHaptique *elt);

	void removeAll();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();
	
	virtual void setCentreRelatif(const int &x, const int &y);

};

#endif