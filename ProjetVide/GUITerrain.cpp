#include "GUITerrain.h"

BEGIN_EVENT_TABLE(GUITerrain, wxPanel)
	EVT_MOTION(GUITerrain::onSourisMove) 
END_EVENT_TABLE();

GUITerrain::GUITerrain(wxWindow* parent, Terrain *terrain, wxWindowID id) : wxPanel(parent, id), terrain(terrain)
{
	guiHuman = new GUIRaquette(terrain->getHuman());
	guiIA = new GUIRaquette(terrain->getIa());
	guiPalet = new GUIPalet(terrain->getPalet());
}

GUITerrain::~GUITerrain()
{
	delete guiHuman;
	delete guiIA;
	delete guiPalet;
}

void GUITerrain::dessiner(wxClientDC *dc)
{
	guiHuman->dessiner(dc);
	guiIA->dessiner(dc);
	guiPalet->dessiner(dc);
}

void GUITerrain::onSourisMove(wxMouseEvent& event)
{
	//wxMessageBox( wxT(wxString::Format("%d", event.GetX()) + " " + wxString::Format("%d", event.GetY())), wxT("Info mouse motion"), wxICON_INFORMATION);
	//modification du modèle
	terrain->getHuman()->setX(event.GetX());
	terrain->getHuman()->setY(event.GetY());
}
