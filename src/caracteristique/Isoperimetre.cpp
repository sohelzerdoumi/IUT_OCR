#include "caracteristique/Isoperimetre.h"
#include <iostream>
#include <cmath>

#define PONDERATION_ISOPERIMETRE 1.0f

using namespace std;

Isoperimetre::Isoperimetre(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "ISOPERIMETRE", PONDERATION_ISOPERIMETRE)
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

    _vecteur.push_back(  (float)perimetre / (4 * M_PI * surface));
    //cout << perimetre <<"  " << surface << "  "<<  _vecteur[0] << endl;
}
