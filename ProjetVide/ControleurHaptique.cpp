#include "ControleurHaptique.h"

ControleurHaptique::ControleurHaptique() : ElementHaptique(), list(std::vector<ElementHaptique*>())
{

}

ControleurHaptique::~ControleurHaptique()
{

}

ElementHaptique* ControleurHaptique::add(ElementHaptique *elt)
{
	list.push_back(elt);
	return elt;
}

void ControleurHaptique::removeAll()
{
	for(int i = 0; i < list.size(); i++)
	{
		delete list[i];
		list[i] = NULL;
	}
}

void ControleurHaptique::recentrer()
{
	for(int i = 0; i < list.size(); i++)
		list[i]->recentrer();
}

void ControleurHaptique::Start()
{
	for(int i = 0; i < list.size(); i++)
		list[i]->Start();
}

void ControleurHaptique::Stop()
{
	for(int i = 0; i < list.size(); i++)
		list[i]->Stop();
}

void ControleurHaptique::setCentreRelatif(const int &x, const int &y)
{
	for(int i = 0; i < list.size(); i++)
		list[i]->setCentreRelatif(x, y);
}
