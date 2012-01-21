#include "Observer.h"

Observable::Observable() : list(std::set<Observer*>())
{
}

void Observable::addObserver(Observer *o)
{
	list.insert(o);
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
	for(std::set<Observer*>::iterator i = list.begin(); i != list.end(); ++i)
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
		for(std::set<Observer*>::iterator i = list.begin(); i != list.end(); ++i)
			(*i)->update(this, data);
		changed = false;
	}
}
