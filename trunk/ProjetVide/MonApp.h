/*!
 * \file ManApp.h
 * Fichier de base d'application
 */

#ifndef _MONAPP_H
#define _MONAPP_H

	/*#include <wx/wxprec.h>

	#ifdef __BORLANDC__
	#pragma hdrstop
	#endif

	#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#endif*/

	#include <wx/wx.h>
	
	/*!
	 * \class MonApp
     * \brief Permet de lancer l'application
     *
     *  Classe permettant de lancer l'application
     */
	class MonApp : public wxApp
	{
		virtual bool OnInit();
	};

#endif