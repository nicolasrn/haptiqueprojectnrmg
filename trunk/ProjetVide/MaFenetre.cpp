#include "MaFenetre.h"

using namespace std;

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_MENU(APPNOUVEAUJEU, MaFenetre::onNouveauJeu)
	EVT_MENU(APPQUIT, MaFenetre::onQuit)
	EVT_MOVE(MaFenetre::onWindowMove)
END_EVENT_TABLE();

MaFenetre::MaFenetre(const wxString& title, const int &width, const int &height) : wxFrame(NULL,wxID_ANY,title), width(width), height(height), mEnclos(NULL), mSouris(NULL)
{
	this->terrain = new Terrain(width, height);
	this->guiTerrain = new GUITerrain(this, terrain);
	
	this->controleur = new Controleur(terrain, guiTerrain);
	this->controleur->start();
	
	this->creerMenu();

	mCentreEnclosRelatif = wxPoint(guiTerrain->GetSize().GetWidth()/2, guiTerrain->GetSize().GetHeight()/2);
	mSouris = new CImmMouse;
	if (!mSouris->Initialize(wxGetInstance(), this->GetHandle()))
	{
		wxMessageBox("erreur souris");
		delete mSouris;
		mSouris = NULL;
		this->Close();
	}

	mEnclos = NULL;
	mEnclos = new CImmEnclosure();
	wxPoint temp(mCentreEnclosRelatif);
	ClientToScreen(&temp.x, &temp.y);
	POINT centreEnclos;
	centreEnclos.x = temp.x;
	centreEnclos.y = temp.y;
	if (!mEnclos->Initialize(mSouris,
		this->guiTerrain->GetSize().GetWidth(), this->guiTerrain->GetSize().GetHeight(), // dimensions
			-10000, -10000, //dureté des murs
			10, 10, //épaisseur des murs
			10000, 10000, //saturation des murs/force max
			IMM_STIFF_ANYWALL,//masque d’application du retour
			0x0, //masque de clipping
			centreEnclos, //centre
			NULL, //effet dans l’enclos
			0, //angle de rotation de l’enclos, exprimé en centigrade
			//45° ⇒ 4500 !!!
			IMM_PARAM_NODOWNLOAD))
	{
		delete mEnclos;
		mEnclos = NULL;
	}
	
	mEnclos->Start();
}

MaFenetre::~MaFenetre()
{
	delete terrain;
	delete guiTerrain;

	terrain = NULL;
	guiTerrain = NULL;
	
	if (mEnclos != NULL)
		delete mEnclos;
	if (mSouris != NULL)
		delete mSouris;

	mEnclos = NULL;
	mSouris = NULL;
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
	if (mEnclos != NULL && mSouris != NULL)
	{
		wxPoint centre(mCentreEnclosRelatif);
		ClientToScreen(&centre.x, &centre.y);
		mEnclos->ChangeCenter(centre.x, centre.y);
		Refresh();
	}
}