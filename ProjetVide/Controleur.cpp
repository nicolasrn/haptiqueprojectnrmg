#include "Controleur.h"

BEGIN_EVENT_TABLE(Controleur, wxEvtHandler)
	EVT_TIMER(-1, Controleur::compute)
END_EVENT_TABLE();

bool Controleur::marque = false;

Controleur::Controleur(Terrain *terrain, GUITerrain *guiTerrain) : 
	wxEvtHandler(), terrain(terrain), guiTerrain(guiTerrain), humainPlayer(new JoueurHuman()), IaPlayer(new JoueurIA()), timer(new wxTimer(this))
{
	Controleur::marque = false;
	this->humainPlayer->addObserver(this->guiTerrain->getBandeau()->getGUIScoreHuman());
	this->IaPlayer->addObserver(this->guiTerrain->getBandeau()->getGUIScoreIA());
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

void Controleur::reset()
{
	humainPlayer->setScore(0);
	IaPlayer->setScore(0);
	
	guiTerrain->getBandeau()->getGUIScoreHuman()->concat(wxString::Format("%d", 0));
	guiTerrain->getBandeau()->getGUIScoreIA()->concat(wxString::Format("%d", 0));
}

void Controleur::compute(wxTimerEvent& event)
{
	//*
	//controle
	Element *collisione = NULL;
	Palet *palet = terrain->getPalet();
	int vx = 0, vy = 0;
	int dx = 0, dy = 0;
	Controleur::marque = false;

	if (humainPlayer->getScore() == 7 || IaPlayer->getScore() == 7)
	{
		this->stop();
		wxMessageBox(humainPlayer->getScore() == 7 ? "Féliciation" : "Doooomaaaaage", "Résultat");
	}

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
		{
			// donc dans le cas ou le palet touche le mur nord ou sud on vérifie si il y a but
			if (dy == 1 || dy == -1)
			{
				But *but = NULL;
				Joueur *j = NULL;
				if (dy == -1)
				{
					but = terrain->getButSud();
					j = IaPlayer;
				}
				else
				{
					but = terrain->getButNord();
					j = humainPlayer;
				}

				//dans ce cas la detection sur les y est deja faite car on detecte les buts uniquement si 
				//l'etremite nord ou sud du terrain est touche
				if (but->getX() < palet->getX() && palet->getX() < but->getX() + but->getWidth() && Controleur::marque == false) //détection sur les x	
				{
					Controleur::marque = true;
					j->incrementScore();
					palet->setVecteurDeplacement(0, 0);
					palet->setX(terrain->getWidth()/2);
					palet->setY(terrain->getHeight()/2);
					dx = dy = 0;
				}
			}
			palet->setVecteurDeplacement(dx+palet->getVx(), dy+palet->getVy());
		}
		palet->compute();
	
		//mise à jour de la vue
		wxClientDC dc(guiTerrain);
		dc.Clear();
		guiTerrain->dessiner(&dc);
		//*/
	}
}
