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
	#include "GestionCollision.h"
	#include "Controleur.h"
	#include "GestionnaireSouris.h"
	#include "ControleurHaptique.h"
	
	#include "ButHaptique.h"
	
	#include "DebutPartie.h"
	#include "FinPartie.h"

	#include "TerrainHaptique.h"
	#include "TerrainNormalHaptique.h"
	#include "TerrainTresGlissantHaptique.h"
	#include "TerrainGluantHaptique.h"

	#include "PaletSolidHaptique.h"
	#include "PaletElastiqueHaptique.h"

	/*!
	 * \enum 
	 * \brief Liste d'identifiant de la fenetre
	 * Liste d'identifiant de la fenetre
	 */
	enum
	{
		APPQUIT = wxID_HIGHEST + 1,
		APPNOUVEAUJEU,
		APPPAUSEJEU,
		APPNIVEAU,
		APPTERRAINNORMAL,
		APPTERRAINTRESGLISSANT,
		APPTERRAINGLUANT,
		APPPALETSOLID,
		APPPALETELSATIQUE
	};
	
	/*!
	 * \brief Classe de la fenetre
	 * Classe qui permet la création de l'interface de base
	 */
	class MaFenetre : public wxFrame
	{
	private:

		Terrain *terrain; /*!< Modele représentant le terrain*/
		GUITerrain *guiTerrain; /*!< Vue représentant le terrain*/

		int width, height;/*!< Représente la taille et la hauteur de la vue*/

		Controleur *controleur;/*!< Le controleur jeu */
		ControleurHaptique *controleurHaptique;/*!< Le controleur haptique */

		/*!< Les menu items des différent menu terrain */
		wxMenuItem *terrainGlissant, *terrainNormal, *terrainGluant;
		
		/*!< Les menu items des différent menu palet */
		wxMenuItem *paletElastique, *paletSolid;

		ButHaptique *butHaptique;/*!< pointeur vers l'element butHaptique car les observateurs et controleurHaptique ne détruisent pas les éléments */
		DebutPartie *debutPartie;/*!< pointeur vers l'element debut de la partie car les observateurs et controleurHaptique ne détruisent pas les éléments */
		FinPartie *finPartie;/*!< pointeur vers l'element fin de la partie car les observateurs et controleurHaptique ne détruisent pas les éléments */
		TerrainHaptique *terrainHaptique;/*!< pointeur vers l'element terrain car les observateurs et controleurHaptique ne détruisent pas les éléments */
		PaletHaptique *paletHaptique;/*!< pointeur vers l'element palet car les observateurs et controleurHaptique ne détruisent pas les éléments */

		/*!
		 * \brief permet la création du menu
		 * permet la création du menu
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
		 * Destructeur détruit tous les pointeurs
		 */
		virtual ~MaFenetre();
		
		/*!
		 * \brief Lance un nouveau jeu
		 * Action permettant de lancer un nouveau jeu
		 * \param event : l'evenement
		 */
		void onNouveauJeu(wxCommandEvent& WXUNUSED(event));
		
		/*!
		 * \brief Met sur pause le jeu courrant
		 * Met sur pause le jeu courrant
		 * \param event : l'evenement
		 */
		void onPause(wxCommandEvent& WXUNUSED(event));

		/*!
		 * Action permettant le choix du terrain et du terrain
		 * \param event : l'evenement
		 */
		void choix(wxCommandEvent& WXUNUSED(event));
		
		/*!
		 * \brief Permet de quitter
		 * Permet de quitter l'application
		 * \param event : l'evenement
		 */
		void onQuit(wxCommandEvent &WXUNUSED(event));
		
		/*!
		 * \brief Action au redimensionnement
		 * Action au redimensionnement
		 * \param event : l'evenement
		 */
		void onWindowMove(wxMoveEvent &WXUNUSED(event));
		
		DECLARE_EVENT_TABLE();
	};

#endif