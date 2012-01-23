#include "ButHaptique.h"

ButHaptique::ButHaptique() : ElementHaptique(), Observer(), period(NULL)
{
	if (mProjet->OpenFile("effet.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		period = new CImmPeriodic();
		if (!period->InitializeFromProject(*mProjet, "Periodic", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete period;
			period = NULL;
			wxMessageBox("erreur period");
		}
		period->ChangeDuration(1000);
		period->ChangeMagnitude(10000);
	}
}

ButHaptique::~ButHaptique()
{
	if (period != NULL)
		delete period;
	if (mProjet != NULL)
		delete mProjet;
	period = NULL;
	mProjet = NULL;
}

void ButHaptique::recentrer()
{
}

void ButHaptique::Start()
{
	period->Start(1);
}

void ButHaptique::Stop()
{
	period->Stop();
}

void ButHaptique::update(Observable *o, Data *data)
{
	DataBut *d = dynamic_cast<DataBut*>(data);
	if (d != NULL)
		this->Start();
}
