#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPQUIT, MaFenetre::onQuit)
END_EVENT_TABLE();

MaFenetre::MaFenetre(const wxString& title, const int &width, const int &height): wxFrame(NULL,wxID_ANY,title), width(width), height(height)
{
	this->SetSize(width, height);
	this->terrain = new Terrain(width, height);
	this->guiTerrain = new GUITerrain(this, terrain);

	this->controleur = new Controleur(terrain, guiTerrain);
	this->controleur->start(1);
	//this->timer = new wxTimer(this);
	//this->timer->Start(1);

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
	this->controleur->stop();
	this->controleur->start(1);
	//timer->Stop();
	//timer->Start(1);
}

void MaFenetre::onQuit(wxCommandEvent& event)
{
	//timer->Stop();
	this->controleur->stop();
	Close();
}
