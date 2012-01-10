#include "Controleur.h"

BEGIN_EVENT_TABLE(Controleur, wxEvtHandler)
	EVT_TIMER(-1, Controleur::compute)
END_EVENT_TABLE();

Controleur::Controleur(Terrain *terrain, GUITerrain *guiTerrain) : wxEvtHandler(), terrain(terrain), guiTerrain(guiTerrain), humainPlayer(new Joueur()), IaPlayer(new Joueur())
{
	timer = new wxTimer(this);
}

Controleur::~Controleur()
{
	delete humainPlayer;
	delete IaPlayer;
}

void Controleur::start(int ms)
{
	timer->Start(ms);
}

void Controleur::stop()
{
	timer->Stop();
}

void Controleur::compute(wxTimerEvent& event)
{
	//*
	//controle
	Element *collisione = NULL;
	Palet *palet = terrain->getPalet();
	int vx = 0, vy = 0;
	int dx = 0, dy = 0;

	if (palet != NULL)
	{
		if (GestionCollision::isCircleCollisionBetween(palet, terrain->getList(), &collisione))
		{
			//définition du vecteur de déplacement du palet
		
			vy = (collisione->getY() < palet->getY()) ? 1 : -1;
			vx = (collisione->getX() < palet->getX()) ? 1 : -1;
		
			palet->setVecteurDeplacement(vx, vy);
		}

		if (GestionCollision::isCircleGroundCollisionBetween(palet, terrain, &dx, &dy))
			// ici ajouter la vérification avec les buts
			palet->setVecteurDeplacement(dx+palet->getVx(), dy+palet->getVy());

		palet->compute();
	
		//mise à jour de la vue
		wxClientDC dc(guiTerrain);
		dc.Clear();
		guiTerrain->dessiner(&dc);
		//*/
	}
}
