#include "caracteristique/Zoning.h"

#define ZONING_LARGEUR 5
#define ZONING_HAUTEUR 5
#define PONDERATION_ZONING 150.0f

Zoning::Zoning(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "ZONING", PONDERATION_ZONING )
{
    //ctor
}

Zoning::~Zoning()
{
    //dtor
}


void Zoning::generate(){
    _vecteur.clear();
    double   _zone[ZONING_LARGEUR][ZONING_HAUTEUR];
    int largeur = _cimg->width()/ZONING_LARGEUR;
    int hauteur = _cimg->height()/ZONING_HAUTEUR;
    for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l < ZONING_HAUTEUR ; l++){
             _zone[c][l] = _cimg->get_crop( c*largeur, l*hauteur ,0,
                                         (c+1)*largeur , (l+1)*hauteur,0 ).mean();
             _vecteur.push_back(_zone[c][l]*100.0f/255);

        }


}
