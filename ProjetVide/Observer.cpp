#include "Observer.h"

Observable::Observable() : list(std::vector<Observer*>())
{
}

void Observable::addObserver(Observer *o)
{
	list.push_back(o);
}

bool Observable::hasChanged()const
{
	return changed;
}
	
void Observable::setChanged()
{
	changed = true;
}
	
void Observable::clearChanged()
{
	changed = false;
}

void Observable::deleteObserver(Observer *o)
{
	for(std::vector<Observer*>::iterator i = list.begin(); i != list.end(); ++i)
		if ((*i) == o)
			list.erase(i);
}
	
void Observable::deleteObservers()
{
	list.clear();
}

void Observable::notifyObservers(Data *data)
{
	if (changed)
	{
		for(std::vector<Observer*>::iterator i = list.begin(); i != list.end(); ++i)
			(*i)->update(this, data);
		changed = false;
	}
}
