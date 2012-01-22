#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPQUIT, MaFenetre::onQuit)
	EVT_MENU(APPTERRAINNORMAL, MaFenetre::choix)
	EVT_MENU(APPTERRAINTRESGLISSANT, MaFenetre::choix)
	EVT_MENU(APPTERRAINGLUANT, MaFenetre::choix)
	EVT_MENU(APPPALETSOLID, MaFenetre::choix)
	EVT_MENU(APPPALETELSATIQUE, MaFenetre::choix)
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
	PaletSolidHaptique *tmp = NULL;
	ButHaptique *tmpb = NULL;
	if (GestionnaireSouris::ActivationGestionnaire)
	{
		controleurHaptique = new ControleurHaptique();
		controleurHaptique->add(new TerrainNormalHaptique(guiTerrain, terrain));
		tmp = new PaletSolidHaptique(guiTerrain, terrain);
		controleurHaptique->add(tmp);
		tmpb = new ButHaptique();
		controleurHaptique->add(tmpb);

		controleur->addObserver(tmp);
		controleur->addObserver(tmpb);
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
	delete controleur;

	controleur = NULL;
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
	
	wxMenu *menuDifficulteTerrain = new wxMenu;
	menuDifficulteTerrain->AppendRadioItem(APPTERRAINNORMAL, "Normale");
	menuDifficulteTerrain->AppendRadioItem(APPTERRAINTRESGLISSANT, "Très glissant");
	menuDifficulteTerrain->AppendRadioItem(APPTERRAINGLUANT, "Gluant");

	wxMenu *menuTypePalet = new wxMenu;
	menuTypePalet->AppendRadioItem(APPPALETSOLID, "Solid");
	menuTypePalet->AppendRadioItem(APPPALETELSATIQUE, "Elastique");
	
	menuPerso->AppendSubMenu(menuDifficulteTerrain, "Difficulte terrain");
	menuPerso->AppendSubMenu(menuTypePalet, "Type palet");
	
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

void MaFenetre::choix(wxCommandEvent& event)
{
	wxMessageBox(wxString::Format("%d", event.GetId()));
}

void MaFenetre::onWindowMove(wxMoveEvent &WXUNUSED(event))
{
	if (GestionnaireSouris::ActivationGestionnaire)
	{
		controleurHaptique->recentrer();
	}
}
