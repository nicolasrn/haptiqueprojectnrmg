#include "TerrainTresGlissantHaptique.h"

TerrainTresGlissantHaptique::TerrainTresGlissantHaptique(GUITerrain *fenetre, Terrain *terrain) :
	ElementHaptique(), fenetre(fenetre), terrain(terrain), mEnclos(NULL)
{
	debut = true;
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
}

TerrainTresGlissantHaptique::~TerrainTresGlissantHaptique()
{
	if (mEnclos != NULL)
		delete mEnclos;
	
	mEnclos = NULL;
}

void TerrainTresGlissantHaptique::recentrer()
{
	wxPoint centre(mCentreEnclosRelatif);
	fenetre->ClientToScreen(&centre.x, &centre.y);
	mEnclos->ChangeCenter(centre.x, centre.y);
}

void TerrainTresGlissantHaptique::Start()
{
	mEnclos->Start();
}

void TerrainTresGlissantHaptique::Stop()
{
	mEnclos->Stop();
}