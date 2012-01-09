#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_TIMER(-1, MaFenetre::onTimerEvent)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPQUIT, MaFenetre::onQuit)
END_EVENT_TABLE();

MaFenetre::MaFenetre(const wxString& title, const int &width, const int &height): wxFrame(NULL,wxID_ANY,title), width(width), height(height)
{
	this->SetSize(width, height);
	this->terrain = new Terrain(width, height);
	this->guiTerrain = new GUITerrain(this, terrain);
	this->timer = new wxTimer(this);
	this->timer->Start(100);

	this->creerMenu();
}

MaFenetre::~MaFenetre()
{
	delete terrain;
}

void MaFenetre::creerMenu()
{
	wxMenu *menuFichier = new wxMenu;
	menuFichier->Append(APPNOUVEAUJEU, "Nouveau jeu");
    menuFichier->Append(APPQUIT, "Quitter");

    wxMenuBar *menuBarre = new wxMenuBar();
    menuBarre->Append(menuFichier,("&Fichier"));

    SetMenuBar(menuBarre);
}

void MaFenetre::onNouveauJeu(wxCommandEvent& event)
{
	timer->Start(100);
}

void MaFenetre::onQuit(wxCommandEvent& event)
{
	Close();
}

/**
 * événement controleur
 */
void MaFenetre::onTimerEvent(wxTimerEvent& event)
{
	//*
	//controle
	GestionCollision::isCollisionBetween(terrain->getPalet(), terrain->getList());

	//mise à jour de la vue
	wxClientDC dc(guiTerrain);
	dc.Clear();
	guiTerrain->dessiner(&dc);
	//*/
}
