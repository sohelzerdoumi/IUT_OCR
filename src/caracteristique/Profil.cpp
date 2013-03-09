#include "caracteristique/Profil.h"

#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cimg_library;


Profil::Profil(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "PROFIL", getConfigValueFloat("ocr.caracteristique.profil.ponderation") )
{
    _data_quantity  = 0;
}

void Profil::generate(){
    _data_quantity = 0;
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
        ponderationCase =  pow( 1.005f , -pow( c - 15, 2)  );
        _vecteur.push_back( (tmp_int* ponderationCase) *100.0/hauteur);
        _data_quantity += tmp_int;
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
        _vecteur.push_back(tmp_int*100.0/largeur);
    }


}

Profil::~Profil() {}

int                     Profil::getSize(){
    return _vecteur.size();
}

int                     Profil::getDataQuantity(){
    return _data_quantity;
}

Profil::Profil(const Profil & h)
: Caracteristique(h)
{
    _cimg= h._cimg;
    _vecteur = h._vecteur;
    _data_quantity = h._data_quantity;

}
