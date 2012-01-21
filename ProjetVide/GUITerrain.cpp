#include "GUITerrain.h"

BEGIN_EVENT_TABLE(GUITerrain, wxPanel)
	EVT_MOTION(GUITerrain::onSourisMove) 
END_EVENT_TABLE();

GUITerrain::GUITerrain(wxWindow* parent, Terrain *terrain, wxWindowID id) : wxPanel(parent, id), ElementAAfficher(), terrain(terrain)
{
	//cntLabel = wxString::Format("Score : Human %d - IA %d", scoreHuman, scoreIA);
	//label = new wxStaticText(this, -1, cntLabel);
	bandeau = new GUIBandeau(this);
	parent->SetSize(terrain->getWidth(), terrain->getHeight() + bandeau->getHeight());
	terrain->setYStart(bandeau->getHeight() + 3);
	
	terrain->getButNord()->setY(terrain->getYStart() + 1);
	
	guiHuman = new GUIRaquette(terrain->getHuman());
	guiIA = new GUIRaquette(terrain->getIa());
	guiPalet = new GUIPalet(terrain->getPalet());
	
	guiButNord = new GUIBut(terrain->getButNord());
	guiButSud = new GUIBut(terrain->getButSud());
}

GUITerrain::~GUITerrain()
{
	delete bandeau;
	delete guiHuman;
	delete guiIA;
	delete guiPalet;
	delete guiButNord;
	delete guiButSud;

	bandeau = NULL;
	guiPalet = NULL;
	guiIA = NULL;
	guiHuman = NULL;
	guiButNord = NULL;
	guiButSud = NULL;
}

GUIPalet* GUITerrain::getGuiPalet()
{
	return guiPalet;
}

void GUITerrain::dessiner(wxClientDC *dc)
{
	dc->DrawLine(0, (this->terrain->getHeight() - (bandeau->getHeight() + 3))/2, this->terrain->getWidth(), (this->terrain->getHeight() - (bandeau->getHeight() + 3))/2);

	//delegation aux objets de se dessiner
	guiHuman->dessiner(dc);
	guiIA->dessiner(dc);
	guiPalet->dessiner(dc);
	
	guiButNord->dessiner(dc);
	guiButSud->dessiner(dc);
}

void GUITerrain::onSourisMove(wxMouseEvent& event)
{
	//wxMessageBox( wxT(wxString::Format("%d", event.GetX()) + " " + wxString::Format("%d", event.GetY())), wxT("Info mouse motion"), wxICON_INFORMATION);
	//modification du modèle
	terrain->getHuman()->setX(event.GetX());
	terrain->getHuman()->setY(event.GetY());
}

GUIBandeau* GUITerrain::getBandeau()const
{
	return this->bandeau;
}

GUIRaquette*  GUITerrain::getHumanRaquette()const
{
	return this->guiHuman;
}

GUIRaquette*  GUITerrain::getIaRaquette()const
{
	return this->guiIA;
}
