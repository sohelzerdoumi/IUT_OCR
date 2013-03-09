#include "caracteristique/Zoning.h"

Zoning::Zoning(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "ZONING", getConfigValueFloat("ocr.caracteristique.zoning.ponderation") )
{
    //ctor
}

Zoning::~Zoning()
{
    //dtor
}


void Zoning::generate(){
    _vecteur.clear();
    int ZONING_LARGEUR = getConfigValueInt("ocr.caracteristique.zoning.nbColonnes");
    int ZONING_HAUTEUR = getConfigValueInt("ocr.caracteristique.zoning.nbLignes") ;
    double   _zone[50][50];
    int largeur = _cimg->width()/ZONING_LARGEUR;
    int hauteur = _cimg->height()/ZONING_HAUTEUR;

    for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l < ZONING_HAUTEUR ; l++){
             _zone[c][l] = _cimg->get_crop( c*largeur,      l*hauteur ,0,
                                            (c+1)*largeur , (l+1)*hauteur,0 ).mean();
             _vecteur.push_back(_zone[c][l]*100.0f/255); // pourcentage

        }


}
