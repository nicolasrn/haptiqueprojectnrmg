#include "MaFenetre.h"

BEGIN_EVENT_TABLE(MaFenetre, wxFrame)
	EVT_TIMER(-1, MaFenetre::onTimerEvent)
END_EVENT_TABLE();

using namespace std;

MaFenetre::MaFenetre(const wxString& title, const int &width, const int &height): wxFrame(NULL,wxID_ANY,title), width(width), height(height)
{
	this->SetSize(width, height);
	terrain = new Terrain(width, height);
	guiTerrain = new GUITerrain(this, terrain);

	timer = new wxTimer(this);
	timer->Start(1);
}

MaFenetre::~MaFenetre()
{
	delete terrain;
}

void MaFenetre::onTimerEvent(wxTimerEvent& event)
{
	//*
	wxClientDC dc(guiTerrain);
	dc.Clear();
	guiTerrain->dessiner(&dc);
	//*/
}
