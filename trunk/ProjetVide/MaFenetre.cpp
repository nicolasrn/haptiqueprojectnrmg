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
	this->terrain = new Terrain(width, height);

	try
	{
		GestionnaireSouris::getInstance(wxGetInstance(), this->GetHandle());
		this->guiTerrain = new GUITerrainHaptique(this, terrain);

		wxMessageBox("Effet de la souris haptique activée");
	}
	catch(const std::exception &e)
	{
		wxMessageBox(e.what());

		if (this->guiTerrain != NULL)
		{
			delete guiTerrain;
			guiTerrain = NULL;
		}
		this->guiTerrain = new GUITerrain(this, terrain);
	}

	this->controleur = new Controleur(terrain, guiTerrain);
	this->controleur->start();
	
	this->creerMenu();
}

MaFenetre::~MaFenetre()
{
	delete terrain;
	delete guiTerrain;

	terrain = NULL;
	guiTerrain = NULL;
}

void MaFenetre::creerMenu()
{
	wxMenu *menuFichier = new wxMenu;
	menuFichier->Append(APPNOUVEAUJEU, "Nouveau jeu");
    menuFichier->Append(APPQUIT, "Quitter");
	menuFichier->Append(APPQUIT, "Niveau");
	menuFichier->Append(APPQUIT, "Palet");

    wxMenuBar *menuBarre = new wxMenuBar();
    menuBarre->Append(menuFichier,("&Fichier"));

    SetMenuBar(menuBarre);
}

void MaFenetre::onNouveauJeu(wxCommandEvent &WXUNUSED(event))
{
	this->controleur->stop();

	this->controleur->reset();
	this->controleur->start();
}

void MaFenetre::onQuit(wxCommandEvent &WXUNUSED(event))
{
	this->controleur->stop();
	Close();
}

void MaFenetre::onWindowMove(wxMoveEvent &WXUNUSED(event))
{
	if (guiTerrain != NULL && GestionnaireSouris::getInstance()->getSouris() != NULL)
	{
		wxPoint centre(((GUITerrainHaptique*)guiTerrain)->getCentreEnclosRelatif());
		ClientToScreen(&centre.x, &centre.y);
		((GUITerrainHaptique*)guiTerrain)->getEnclos()->ChangeCenter(centre.x, centre.y);
	}
}