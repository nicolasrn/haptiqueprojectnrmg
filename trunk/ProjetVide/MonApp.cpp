#include "MonApp.h"
#include "MaFenetre.h"

IMPLEMENT_APP(MonApp);

bool MonApp::OnInit()
{ 
	//création de la fenêtre principale
	MaFenetre *fen = new MaFenetre(wxT("Ma première application"), 300, 600);
	//affichage de la fenêtre
	fen->Show(true);
	return true;
}