#include "ControleurHaptique.h"

ControleurHaptique::ControleurHaptique() : ElementHaptique(), list(std::vector<ElementHaptique*>())
{

}

ControleurHaptique::~ControleurHaptique()
{

}

void ControleurHaptique::add(ElementHaptique *elt)
{
	list.push_back(elt);
}

void ControleurHaptique::removeAll()
{
	/*for(unsigned int i = 0; i < list.size(); i++)
	{
		delete list[i];
		list[i] = NULL;
	}*/
	list.clear();
}

void ControleurHaptique::recentrer()
{
	for(std::vector<ElementHaptique*>::iterator i = list.begin(); i != list.end(); i++)
		(*i)->recentrer();
}

void ControleurHaptique::Start()
{
	for(std::vector<ElementHaptique*>::iterator i = list.begin(); i != list.end(); i++)
	{
		if ((*i)->getDebut())
		{
			(*i)->Start();
			(*i)->setDebut(true);
		}
	}
}

void ControleurHaptique::Stop()
{
	for(std::vector<ElementHaptique*>::iterator i = list.begin(); i != list.end(); i++)
		(*i)->Stop();
}

void ControleurHaptique::setCentreRelatif(const int &x, const int &y)
{
	for(std::vector<ElementHaptique*>::iterator i = list.begin(); i != list.end(); i++)
		(*i)->setCentreRelatif(x, y);
}
