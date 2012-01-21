#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPQUIT, MaFenetre::onQuit)
	EVT_MOVE(MaFenetre::onWindowMove)
END_EVENT_TABLE();

MaFenetre::MaFenetre(const wxString& title, const int &width, const int &height) : wxFrame(NULL,wxID_ANY,title), width(width), height(height)//, mEnclos(NULL), mSouris(NULL)
{
	this->guiTerrain = NULL;
	this->guiTerrain = NULL;
	this->controleur = NULL;
	this->controleurHaptique = NULL;
	
	this->terrain = new Terrain(width, height);
	this->guiTerrain = new GUITerrain(this, terrain);
	
	this->controleur = new Controleur(terrain, guiTerrain);

	GestionnaireSouris::getInstance(wxGetInstance(), this->GetHandle());
	PaletHaptique *tmp = NULL;
	if (GestionnaireSouris::ActivationGestionnaire)
	{
		controleurHaptique = new ControleurHaptique();
		controleurHaptique->add(new TerrainHaptique(guiTerrain, terrain));
		tmp = new PaletHaptique(guiTerrain, terrain);
		controleurHaptique->add(tmp);
		controleur->addObserver(tmp);
	}

	this->controleurHaptique->Start();
	this->controleur->start();

	this->creerMenu();
}

MaFenetre::~MaFenetre()
{
	delete terrain;
	delete guiTerrain;
	delete controleurHaptique;

	controleurHaptique = NULL;
	terrain = NULL;
	guiTerrain = NULL;
}

void MaFenetre::creerMenu()
{
	wxMenu *menuFichier = new wxMenu;
	menuFichier->Append(APPNOUVEAUJEU, "Nouveau jeu");
    menuFichier->Append(APPQUIT, "Quitter");
	wxMenu *menuPerso = new wxMenu;		
	menuPerso->Append(APPNIVEAU, "Niveau");
	menuPerso->Append(APPPERSONNALISATION, "Palet");

    wxMenuBar *menuBarre = new wxMenuBar();
	menuBarre->Append(menuFichier, wxT("&Fichier"));
	menuBarre->Append(menuPerso, wxT("&Personnalisation"));

    SetMenuBar(menuBarre);
}

void MaFenetre::onNouveauJeu(wxCommandEvent &WXUNUSED(event))
{
	this->controleurHaptique->Stop();
	this->controleurHaptique->Start();

	this->controleur->stop();
	this->controleur->reset();
	this->controleur->start();
}

void MaFenetre::onQuit(wxCommandEvent &WXUNUSED(event))
{
	this->controleurHaptique->Stop();
	this->controleur->stop();
	Close();
}

void MaFenetre::onWindowMove(wxMoveEvent &WXUNUSED(event))
{
	if (GestionnaireSouris::ActivationGestionnaire)
	{
		controleurHaptique->recentrer();
	}
}