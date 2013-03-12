#include "caracteristique/Profil.h"

#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cimg_library;


Profil::Profil(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "profil", getConfigValueFloat("ocr.caracteristique.defaut.profil.ponderation") )
{
}

void Profil::generate(){
    _vecteur.clear();
    float ponderationCase;
    int * currentPixel;
    int tmp_int;
    int largeur = _cimg->width();
    int hauteur =  _cimg->height();

    /*
     *  Profil Horiontal
     */

    for(int c = 0; c < largeur ; c++ ){
        tmp_int = 0;

        for(int l = 0 ; l < hauteur ; l++){
            currentPixel = _cimg->data(c,l);
            tmp_int += (currentPixel[0]  < SEUIL );
        }
        ponderationCase =  pow( 1.01f , -pow( c - 15, 2)  );
        _vecteur.push_back( (tmp_int* ponderationCase) *100.0/hauteur);
    }

     /*
     * Profil Vertical
     */
    for(int l = 0 ; l < hauteur ; l++){
        tmp_int = 0;
        for(int c = 0; c < largeur ; c++ ){
            currentPixel = _cimg->data(c,l);
            tmp_int += (currentPixel[0] < SEUIL );
        }
        ponderationCase =  1; //pow( 1.01f , -pow( l - 15, 2)  );
        _vecteur.push_back(tmp_int*ponderationCase*100.0/largeur);
    }


}

Profil::~Profil() {}


Profil::Profil(const Profil & h)
: Caracteristique(h)
{
    _cimg= h._cimg;
    _vecteur = h._vecteur;

}
