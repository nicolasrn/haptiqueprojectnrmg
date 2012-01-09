#ifndef _MAFENETRE_H
#define _MAFENETRE_H
	#include <wx/wxprec.h>
	#ifdef __BORLANDC__
		#pragma hdrstop
	#endif

	#ifndef WX_PRECOMP
		#include <wx/wx.h>
	#endif

	#include <wx/msgdlg.h>
	#include "Terrain.h"
	#include "GUITerrain.h"
	
	class MaFenetre : public wxFrame
	{
	private:
		Terrain *terrain;
		GUITerrain *guiTerrain;

		int width, height;

		wxTimer *timer;


	public:
		// Constructeur
		MaFenetre(const wxString& title, const int &width, const int &height); 
		virtual ~MaFenetre();

		void onTimerEvent(wxTimerEvent& event);
		
		DECLARE_EVENT_TABLE();
	};

#endif