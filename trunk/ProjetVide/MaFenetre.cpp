#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPPAUSEJEU, MaFenetre::onPause)
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
	butHaptique = NULL;
	debutPartie = NULL;
	finPartie = NULL;
	terrainHaptique = NULL;
	paletHaptique = NULL;

	this->guiTerrain = NULL;
	this->guiTerrain = NULL;
	this->controleur = NULL;
	this->controleurHaptique = NULL;
	
	this->terrain = new Terrain(width, height);
	this->guiTerrain = new GUITerrain(this, terrain);
	
	this->controleur = new Controleur(terrain, guiTerrain);
	this->controleurHaptique = new ControleurHaptique();

	this->creerMenu();

	this->choix((wxCommandEvent)0);
}

MaFenetre::~MaFenetre()
{
	delete terrain;
	delete guiTerrain;
	delete controleurHaptique;
	delete controleur;
	delete GestionnaireSouris::getInstance();

	controleur = NULL;
	controleurHaptique = NULL;
	terrain = NULL;
	guiTerrain = NULL;
}

void MaFenetre::creerMenu()
{
	wxMenu *menuFichier = new wxMenu;
	menuFichier->Append(APPNOUVEAUJEU, "Nouveau jeu");
	menuFichier->Append(APPPAUSEJEU, "Pause");
	menuFichier->AppendSeparator();
    menuFichier->Append(APPQUIT, "Quitter");

	wxMenu *menuPerso = new wxMenu;
	
	wxMenu *menuDifficulteTerrain = new wxMenu;
	
	terrainNormal = menuDifficulteTerrain->AppendRadioItem(APPTERRAINNORMAL, "Normale");
	terrainGlissant = menuDifficulteTerrain->AppendRadioItem(APPTERRAINTRESGLISSANT, "Très glissant");
	terrainGluant = menuDifficulteTerrain->AppendRadioItem(APPTERRAINGLUANT, "Gluant");

	wxMenu *menuTypePalet = new wxMenu;
	paletSolid = menuTypePalet->AppendRadioItem(APPPALETSOLID, "Solid");
	paletElastique = menuTypePalet->AppendRadioItem(APPPALETELSATIQUE, "Elastique");
	
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

void MaFenetre::onPause(wxCommandEvent& WXUNUSED(event))
{
	//wxMessageBox("this->controleur->isRunning() = " + wxString::Format("%d", this->controleur->isRunning()));
	if (this->controleur->isRunning())
	{
		this->controleurHaptique->Stop();
		this->controleur->stop();
	}
	else
	{
		this->controleurHaptique->Start();
		this->controleur->start();
	}
}

void MaFenetre::onQuit(wxCommandEvent &WXUNUSED(event))
{
	this->controleurHaptique->Stop();
	this->controleur->stop();
	Close();
}

void MaFenetre::choix(wxCommandEvent& WXUNUSED(event))
{
	try
	{
		GestionnaireSouris::getInstance(wxGetInstance(), GetHandle());
	}
	catch(std::exception e)
	{
		//wxMessageBox(e.what());
	}
	
	controleur->stop();
	controleurHaptique->Stop();

	if (butHaptique != NULL)
		delete butHaptique;

	if (debutPartie != NULL)
		delete debutPartie;

	if (finPartie != NULL)
		delete finPartie;

	if (terrainHaptique != NULL)
		delete terrainHaptique;

	if (paletHaptique != NULL)
		delete paletHaptique;

	butHaptique = NULL;
	debutPartie = NULL;
	finPartie = NULL;
	terrainHaptique = NULL;
	paletHaptique = NULL;

	controleur->deleteObservers();
	controleurHaptique->removeAll();

	if (GestionnaireSouris::ActivationGestionnaire)
	{
		butHaptique = new ButHaptique();
		debutPartie = new DebutPartie();
		finPartie = new FinPartie();
		
		if (terrainNormal->IsChecked())
			terrainHaptique = new TerrainNormalHaptique(guiTerrain, terrain);
		else if (terrainGlissant->IsChecked())
			terrainHaptique = new TerrainTresGlissantHaptique(guiTerrain, terrain);
		else if (terrainGluant->IsChecked())
			terrainHaptique = new TerrainGluantHaptique(guiTerrain, terrain);
		else 
			wxMessageBox("pas de terrain");

		if (paletSolid->IsChecked())
			paletHaptique = new PaletSolidHaptique(guiTerrain, terrain);
		else if (paletElastique->IsChecked())
			paletHaptique = new PaletElastiqueHaptique(guiTerrain, terrain);
		else
			wxMessageBox("pas de palet");

		controleurHaptique->add(butHaptique);
		controleurHaptique->add(debutPartie);
		controleurHaptique->add(finPartie);
		controleurHaptique->add(paletHaptique);
		controleurHaptique->add(terrainHaptique);

		controleur->addObserver(paletHaptique);
		controleur->addObserver(butHaptique);
		controleur->addObserver(finPartie);
	}

	this->controleurHaptique->Start();
	this->controleur->start();
}

void MaFenetre::onWindowMove(wxMoveEvent &WXUNUSED(event))
{
	if (GestionnaireSouris::ActivationGestionnaire)
	{
		controleurHaptique->recentrer();
	}
}
