/*!
 * \file GUITerrain.h
 * Fichier concernant la vue terrain
 */
#pragma once

#ifndef __GUITERRAIN__
#define __GUITERRAIN__

#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/stattext.h>
#include <algorithm>

#include "ElementAAfficher.h"
#include "Terrain.h"
#include "GUIPalet.h"
#include "GUIRaquette.h"
#include "GUIBut.h"
#include "Observer.h"

class GUIText;
class GUIScoreHuman;
class GUIScoreIA;
class GUITerrain;
class GUIBandeau;

/*!
 * \brief la vue terrain
 * Représente la vue du terrain et de ce qui dépend d'elle
 */
class GUITerrain : public wxPanel, public ElementAAfficher
{
protected:
	Terrain *terrain;/*!< Le modele terrain*/

	GUIRaquette *guiHuman, *guiIA; /*!< La vue raquette */
	GUIPalet *guiPalet; /*!< La vue du palet */
	GUIBut *guiButNord, *guiButSud; /*!< La vue des buts */
	GUIBandeau *bandeau;

public:
	/*!
	 * \brief Constructeur
	 * Constructeur de la vue terrain
	 * 
	 * \param parent : la vue parente
	 * \param terrain : modele du terrain
	 * \param id : l'id du composant
	 */
	GUITerrain(wxWindow* parent, Terrain *terrain, wxWindowID id = wxID_ANY);
	
	/*!
	 * \brief Destructeur
	 * Détruit les vues
	 */
	virtual ~GUITerrain();

	/*!
	 * \brief Surcharge pour dessiner
	 * Surcharge pour dessiner
	 * \param dc : ce qui permet de dessiner sur la zone cliente
	 */
	void dessiner(wxClientDC *dc);
	
	/*!
	 * \brief Détecte les mouvements du joueur
	 * Détecte les mouvements du joueur afin de mettre a jour le modele 
	 * \param event : l'évenement
	 */
	void onSourisMove(wxMouseEvent& event);
	
	/*!
	 * \brief Getteur Bandeau
	 * Getteur Bandeau
	 * \return GUIBandeau
	 */
	GUIBandeau* getBandeau()const;
	
	/*!
	 * Getteur raquette palet
	 * \return GUIBandeau
	 */
	GUIPalet* getGuiPalet();
	
	/*!
	 * Getteur raquette humain
	 * \return GUIBandeau
	 */
	GUIRaquette* getHumanRaquette()const;
	
	/*!
	 * Getteur raquette IA
	 * \return GUIBandeau
	 */
	GUIRaquette* getIaRaquette()const;

	DECLARE_EVENT_TABLE();
};

class GUIText : public Observer
{
protected:
	wxStaticText *label;
	wxString cntStatic;

public:
	GUIText(GUITerrain *parent, const wxString &cnt) : Observer(), cntStatic(cnt)
	{
		label = new wxStaticText(parent, wxID_ANY, cnt);
	}

	void concat(const wxString &str)
	{
		wxString tmp = cntStatic;
		tmp.append(str);
		label->SetLabel(tmp);
	}

	void update(Observable *WXUNUSED(o), Data *data)
	{
		this->concat(wxString::Format("%d", ((DataScore*)data)->score));
	}

	int getHeight()const
	{
		return this->label->GetSize().GetHeight();
	}
};

class GUIScoreHuman : public GUIText
{
public:
	GUIScoreHuman(GUITerrain *parent) : GUIText(parent, "Human ")
	{
		label->SetPosition(wxPoint(100, 0));
		this->concat(wxString::Format("%d", 0));
	}
};

class GUIScoreIA : public GUIText
{
public:
	GUIScoreIA(GUITerrain *parent) : GUIText(parent, "IA ")
	{
		label->SetPosition(wxPoint(200, 0));
		this->concat(wxString::Format("%d", 0));
	}
};

class GUIBandeau
{
private:
	GUIText *text;
	GUIScoreHuman *sHuman;
	GUIScoreIA *sIA;

public:
	GUIBandeau(GUITerrain *parent)
	{
		text = new GUIText(parent, "Score : ");
		sHuman = new GUIScoreHuman(parent);
		sIA = new GUIScoreIA(parent);
	}

	virtual ~GUIBandeau()
	{
		delete text;
		delete sHuman;
		delete sIA;

		text = NULL;
		sHuman = NULL;
		sIA = NULL;
	}
	
	int getHeight()const
	{
		return sIA->getHeight();//std::max(sIA->getHeight(), std::max(text->getHeight(), sHuman->getHeight()));
	}

	GUIScoreHuman* getGUIScoreHuman()
	{
		return this->sHuman;
	}
	
	GUIScoreIA* getGUIScoreIA()
	{
		return this->sIA;
	}
};



#endif