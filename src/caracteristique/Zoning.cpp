#include "caracteristique/Zoning.h"

#define PONDERATION_ZONING 1.0f

Zoning::Zoning(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "ZONING" )
{
    //ctor
}

Zoning::~Zoning()
{
    //dtor
}


void Zoning::generate(){
    int largeur = _cimg->width()/ZONING_LARGEUR-1;
    int hauteur = _cimg->height()/ZONING_HAUTEUR-1;
    for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l < ZONING_HAUTEUR ; l++)
            _zone[c][l] = _cimg->get_crop( c*largeur, l*hauteur ,0,
                                         (c+1)*largeur , (l+1)*hauteur,0 ).mean();

}

float         Zoning::getPonderation() const {
    return PONDERATION_ZONING;
};


Vecteur       Zoning::getVector() const{
    Vecteur v;
      for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l <ZONING_HAUTEUR ; l++)
            v.push_back(_zone[c][l]);
    return v;
}
