#include "caracteristique/Isoperimetre.h"
#include <iostream>
#include <cmath>

using namespace std;

Isoperimetre::Isoperimetre(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "isoperimetre", getConfigValueFloat("ocr.caracteristique.defaut.isoperimetre.ponderation"))
{
    //ctor
}

Isoperimetre::~Isoperimetre()
{
    //dtor
}


void Isoperimetre::generate(){
    _vecteur.clear();

    int nombrePixelTotal = _cimg->width()*_cimg->height();
    int surface = nombrePixelTotal - ((*_cimg / 255) ).sum();
    int perimetre = surface - (nombrePixelTotal - ((_cimg->get_dilate(2) / 255) ).sum() );

    _vecteur.push_back(  (float)perimetre / (4 * M_PI * surface)*100.0f/
                       ( (float)(nombrePixelTotal/2) / (4 * M_PI * (nombrePixelTotal-2*_cimg->width() - 2*_cimg->height() ) ) ));
    //cout << perimetre <<"  " << surface << "  "<<  _vecteur[0] << endl;
}
