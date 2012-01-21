﻿#include "TerrainHaptique.h"

TerrainHaptique::TerrainHaptique(GUITerrain *fenetre, Terrain *terrain) : ElementHaptique(), fenetre(fenetre), terrain(terrain), 
	mEnclos(NULL), mProjet(NULL), mTexture(NULL)
{
	mProjet = new CImmProject();
	if (mProjet->OpenFile("RetoursHaptiques.ifr", GestionnaireSouris::getInstance()->getSouris()))
	{
		mTexture = new CImmTexture();
		if (!mTexture->InitializeFromProject(*mProjet, "Texture", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD))
		{
			delete mTexture;
			mTexture = NULL;
		}
	}

	mGran = mProjet->CreateEffect("TerrainGran", GestionnaireSouris::getInstance()->getSouris(), IMM_PARAM_NODOWNLOAD);
	if (!mGran)
	{
		delete mGran;
		mGran = NULL;
	}

	mCentreEnclosRelatif = wxPoint(fenetre->GetSize().GetWidth()/2, fenetre->GetSize().GetHeight()/2);
	if (mEnclos == NULL)
    {
            mEnclos = new CImmEnclosure();
            wxPoint temp(mCentreEnclosRelatif);
            fenetre->ClientToScreen(&temp.x, &temp.y);
            POINT centreEnclos;
            centreEnclos.x = temp.x;
            centreEnclos.y = temp.y;
            if (!mEnclos->Initialize(GestionnaireSouris::getInstance()->getSouris(),
				fenetre->GetSize().GetWidth(), fenetre->GetSize().GetHeight(), // dimensions
                            -10000, -10000, //dureté des murs
                            10, 10, //épaisseur des murs
                            10000, 10000, //saturation des murs/force max
                            IMM_STIFF_ANYWALL,//masque d’application du retour
                            0x0, //masque de clipping
                            centreEnclos, //centre
                            NULL, //effet dans l’enclos
                            0, //angle de rotation de l’enclos, exprimé en centigrade
                            //45° ⇒ 4500 !!!
                            IMM_PARAM_NODOWNLOAD))
		{
			delete mEnclos;
			mEnclos = NULL;
			throw std::exception("erreur initialisation enclos terrain");
		}
    }

	mTexture = new CImmTexture();
	FEELIT_EFFECT e;
	if (!mTexture->Initialize(GestionnaireSouris::getInstance()->getSouris(), 
		e, 
		IMM_PARAM_NODOWNLOAD))
	{
		delete mTexture;
		mTexture = NULL;
		wxMessageBox("erreur texture");
	}
}

TerrainHaptique::~TerrainHaptique()
{
	if (mEnclos != NULL)
		delete mEnclos;
	if (mTexture != NULL)
		delete mTexture;
	if (mGran != NULL)
		delete mGran;

	mEnclos = NULL;
	mTexture = NULL;
	mGran = NULL;
}

void TerrainHaptique::recentrer()
{
	wxPoint centre(mCentreEnclosRelatif);
	fenetre->ClientToScreen(&centre.x, &centre.y);
	mEnclos->ChangeCenter(centre.x, centre.y);
}

void TerrainHaptique::Start()
{
	//mGran->Start();
	//mTexture->Start();
	mEnclos->Start();
}

void TerrainHaptique::Stop()
{
	//mGran->Stop();
	//mTexture->Stop();
	mEnclos->Stop();
}