#include "MonApp.h"
#include "MaFenetre.h"

IMPLEMENT_APP(MonApp);

bool MonApp::OnInit()
{ 
	//cr�ation de la fen�tre principale
	MaFenetre *fen = new MaFenetre(wxT("Ma premi�re application"), 400, 700);
	//affichage de la fen�tre
	fen->Show(true);
	return true;
}