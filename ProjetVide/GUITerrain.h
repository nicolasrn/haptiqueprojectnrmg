#pragma once

#ifndef __GUITERRAIN__
#define __GUITERRAIN__

#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include "Terrain.h"
#include "GUIPalet.h"
#include "GUIRaquette.h"

class GUITerrain : public wxPanel
{
private:
	Terrain *terrain;

	GUIRaquette *guiHuman, *guiIA;
	GUIPalet *guiPalet;

public:
	GUITerrain(wxWindow* parent, Terrain *terrain, wxWindowID id = wxID_ANY);
	~GUITerrain();

	void dessiner(wxClientDC *dc);

	void onSourisMove(wxMouseEvent& event);
	
	DECLARE_EVENT_TABLE();
};

#endif