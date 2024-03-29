#include "Controleur.h"

BEGIN_EVENT_TABLE(Controleur, wxEvtHandler)
	EVT_TIMER(-1, Controleur::compute)
END_EVENT_TABLE();

bool Controleur::marque = false;

Controleur::Controleur(Terrain *terrain, GUITerrain *guiTerrain) : 
	wxEvtHandler(), Observable(), terrain(terrain), guiTerrain(guiTerrain), humainPlayer(new JoueurHuman()), IaPlayer(new JoueurIA()), timer(new wxTimer(this))
{
	Controleur::marque = false;
	this->humainPlayer->addObserver(this->guiTerrain->getBandeau()->getGUIScoreHuman());
	this->IaPlayer->addObserver(this->guiTerrain->getBandeau()->getGUIScoreIA());

	srand((unsigned int)time(NULL));
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

bool Controleur::isRunning()
{
	return timer->IsRunning();
}

void Controleur::stop()
{
	timer->Stop();
}

void Controleur::reset()
{
	humainPlayer->setScore(0);
	IaPlayer->setScore(0);

	terrain->getPalet()->setX(terrain->getWidth()/2);
	terrain->getPalet()->setY((terrain->getHeight()/2 - terrain->getYStart()/2));
	terrain->getPalet()->setVecteurDeplacement(0, 0);

	guiTerrain->getBandeau()->getGUIScoreHuman()->concat(wxString::Format("%d", 0));
	guiTerrain->getBandeau()->getGUIScoreIA()->concat(wxString::Format("%d", 0));
}

void Controleur::compute(wxTimerEvent& WXUNUSED(event))
{
	try
	{
		//*
		//controle
		Element *collisione = NULL;
		Palet *palet = terrain->getPalet();
		double vx = 0, vy = 0;
		double dx = 0, dy = 0;
		Controleur::marque = false;

		if (humainPlayer->getScore() == 7 || IaPlayer->getScore() == 7)
		{
			this->stop();
			this->setChanged();
			DataFinPartie data;
			this->notifyObservers(&data);
			wxMessageBox(humainPlayer->getScore() == 7 ? "F�liciation" : "Doooomaaaaage", "R�sultat");
		}

		if (palet != NULL)
		{
			if (GestionCollision::isCircleCollisionBetween(palet, terrain->getList(), &collisione))
			{
				//d�finition du vecteur de d�placement du palet
				
				//vx = (collisione->getX() < palet->getX()) ? 1 : -1;
				//vy = (collisione->getY() < palet->getY()) ? 1 : -1;
				
				vx = (collisione->getX() < palet->getX()) ? 1 : -1;
				vy = (collisione->getY() < palet->getY()) ? 1 : -1;
				
				palet->setVecteurDeplacement(vx, vy);
				palet->setChanged();
				palet->notifyObservers();
			}

			if (GestionCollision::isCircleGroundCollisionBetween(palet, terrain, &dx, &dy))
			{
				// donc dans le cas ou le palet touche le mur nord ou sud on v�rifie si il y a but
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
					if (but->getX() < palet->getX() && palet->getX() < but->getX() + but->getWidth() && Controleur::marque == false) //d�tection sur les x	
					{
						Controleur::marque = true;
						j->incrementScore();

						this->setChanged();
						DataBut data;
						this->notifyObservers(&data);

						palet->setVecteurDeplacement(0, 0);
						palet->setX(terrain->getWidth()/2);
						palet->setY((terrain->getHeight()/2 - terrain->getYStart()/2));

						terrain->getIa()->setVecteurX(0);

						dx = dy = 0;
					}
				}
				palet->setVecteurDeplacement(dx+palet->getVx(), dy+palet->getVy());
				palet->setChanged();
				palet->notifyObservers();
			}
			//si la souris haptique est pr�sente, si collision entre raquette humain et palet alors declanchement
			if (GestionnaireSouris::ActivationGestionnaire && collisione != NULL && collisione == terrain->getHuman())
			{
				//controleurHaptique->setCentreRelatif(palet->getX(), palet->getY());
				this->setChanged();
				DataCoordonnee data(palet->getX(), palet->getY(), vx, vy);
				this->notifyObservers(&data);
			}

			palet->compute();
			if ((vx + dx != 0 && rand() % 3) || (terrain->getIa()->getX() < 0 || terrain->getIa()->getX() > terrain->getWidth() - terrain->getIa()->getWidth()))
			terrain->getIa()->setVecteurX(vx + dx);

			if (terrain->getIa()->getX() + terrain->getIa()->getVecteurX() <= 0
				|| terrain->getIa()->getX() + terrain->getIa()->getVecteurX() >= terrain->getWidth())
				terrain->getIa()->setVecteurX(0);
			
			terrain->getIa()->deplacer();
			
			//mise � jour de la vue
			wxClientDC dc(guiTerrain);
			dc.Clear();
			guiTerrain->dessiner(&dc);
			//*/
		}
	}
	catch(...)
	{
		wxMessageBox("erreur catcher");
	}
}
