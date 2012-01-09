/*!
 * \file MaFenetre.h
 * Fichier de base d'application
 */

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

	/*!
	 * \enum 
	 * \brief Liste d'identifiant de la fenetre
	 * Liste d'identifiant de la fenetre
	 */
	enum
	{
		APPQUIT = wxID_HIGHEST + 1,
		APPNOUVEAUJEU
	};
	
	/*!
	 * \brief Classe de la fenetre
	 * Classe qui permet la cr�ation de l'interface de base
	 */
	class MaFenetre : public wxFrame
	{
	private:
		Terrain *terrain; /*!< Modele repr�sentant le terrain*/
		GUITerrain *guiTerrain; /*!< Vue repr�sentant le terrain*/

		int width, height;/*!< Repr�sente la taille et la hauteur de la vue*/

		wxTimer *timer; /*!< Va servir de base au controleur */

		/*!
		 * \brief permet la cr�ation du menu
		 * permet la cr�ation du menu
		 */
		void creerMenu();

	public:
		/*!
		 * \brief Constructeur
		 *
		 * Constructeur de la classe MaFenetre
		 *
		 * \param title : titre de la fenetre
		 * \param width : la largeur
		 * \param height : la hauteur
		 */
		MaFenetre(const wxString& title, const int &width, const int &height); 
		
		/*!
		 * \brief Destructeur
		 * Destructeur d�truit tous les pointeurs
		 */
		virtual ~MaFenetre();
		
		/*!
		 * \brief Lance un nouveau jeu
		 * Action permettant de lancer un nouveau jeu
		 * \param event : l'evenement
		 */
		void onNouveauJeu(wxCommandEvent& event);
		
		/*!
		 * \brief Permet de quitter
		 *Permet de quitter l'application
		 * \param event : l'evenement
		 */
		void onQuit(wxCommandEvent& event);
		
		/*!
		 * \brief Methode executer tous les n milliseconde
		 * Permet de mettre a jour l'interface
		 * \param event : l'evenement
		 */
		void onTimerEvent(wxTimerEvent& event);
		
		DECLARE_EVENT_TABLE();
	};

#endif