#pragma once

#ifndef __BUT_HAPTIQUE__
#define __BUT_HAPTIQUE__

#include <IFC.h>
#include "ElementHaptique.h"
#include "GestionnaireSouris.h"
#include "Observer.h"

class ButHaptique : public ElementHaptique, public Observer
{
private:
	CImmPeriodic *period;

public:
	ButHaptique();

	virtual ~ButHaptique();

	virtual void recentrer();

	virtual void Start();

	virtual void Stop();

	virtual void update(Observable *o, Data *data);
};

#endif