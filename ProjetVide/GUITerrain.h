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
	GUIBandeau *bandeau;/*!<Le bandeau */

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

/*!
 * \brief GUI pour l'affichage du texte
 * GUI pour l'affichage du texte
 */
class GUIText : public Observer
{
protected:
	wxStaticText *label;/*!<Le label */
	wxString cntStatic;/*!<Le texte */

public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param parent : l'objet parent
	 * \param cnt : la chaine
	 */
	GUIText(GUITerrain *parent, const wxString &cnt) : Observer(), cntStatic(cnt)
	{
		label = new wxStaticText(parent, wxID_ANY, cnt);
	}
	
	/*!
	 * \brief Destructeur
	 * Destructeur
	 * \param str : la chaine a concatener
	 */
	void concat(const wxString &str)
	{
		wxString tmp = cntStatic;
		tmp.append(str);
		label->SetLabel(tmp);
	}
	
	/*!
	 * \brief Pour la mise a jour
	 * Pour la mise a jour via notifyObservers
	 * \param o : l'observable
	 * \param data : la donnée a transmettre
	 */
	void update(Observable *WXUNUSED(o), Data *data)
	{
		this->concat(wxString::Format("%d", ((DataScore*)data)->score));
	}

	/*!
	 * \brief Getteur de la taille
	 * Getteur de la taille
	 * \return int
	 */
	int getHeight()const
	{
		return this->label->GetSize().GetHeight();
	}
};

/*!
 * \brief GUIScoreHuman pour l'affichage du texte
 * GUIScoreHuman pour l'affichage du texte
 */
class GUIScoreHuman : public GUIText
{
public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param parent : l'objet parent
	 */
	GUIScoreHuman(GUITerrain *parent) : GUIText(parent, "Human ")
	{
		label->SetPosition(wxPoint(100, 0));
		this->concat(wxString::Format("%d", 0));
	}
};

/*!
 * \brief GUIScoreIA pour l'affichage du texte
 * GUIScoreIA pour l'affichage du texte
 */
class GUIScoreIA : public GUIText
{
public:
	/*!
	 * \brief Constructeur
	 * Constructeur
	 * \param parent : l'objet parent
	 */
	GUIScoreIA(GUITerrain *parent) : GUIText(parent, "IA ")
	{
		label->SetPosition(wxPoint(200, 0));
		this->concat(wxString::Format("%d", 0));
	}
};

/*!
 * \brief GUIBandeau pour l'affichage du texte
 * GUIBandeau pour l'affichage du texte
 */
class GUIBandeau
{
private:
	GUIText *text;/*!<GUI du texte a affihcher */
	GUIScoreHuman *sHuman;/*!< GUI pour le score joueur */
	GUIScoreIA *sIA;/*!< GUI pour le score ia */

public:
	/*!
	 * \brief Constructeur
	 * \param parent : le pere
	 */
	GUIBandeau(GUITerrain *parent)
	{
		text = new GUIText(parent, "Score : ");
		sHuman = new GUIScoreHuman(parent);
		sIA = new GUIScoreIA(parent);
	}

	/*!
	 * \brief Destructeur
	 * Destructeur
	 */
	virtual ~GUIBandeau()
	{
		delete text;
		delete sHuman;
		delete sIA;

		text = NULL;
		sHuman = NULL;
		sIA = NULL;
	}
	
	/*!
	 * \brief getter de la taille
	 * \return int
	 */
	int getHeight()const
	{
		return sIA->getHeight();//std::max(sIA->getHeight(), std::max(text->getHeight(), sHuman->getHeight()));
	}
	
	/*!
	 * \brief Getteur de la gui score humain
	 * Getteur de la gui score humain
	 * \return GUIScoreHuman
	 */
	GUIScoreHuman* getGUIScoreHuman()
	{
		return this->sHuman;
	}
	
	/*!
	 * \brief Getteur de la gui score ia
	 * Getteur de la gui score ia
	 * \return GUIScoreHuman
	 */
	GUIScoreIA* getGUIScoreIA()
	{
		return this->sIA;
	}
};



#endif