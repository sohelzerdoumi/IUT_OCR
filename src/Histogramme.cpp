#include "Histogramme.h"

#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cimg_library;


Histogramme::Histogramme(cimg_library::CImg<int>  *  cimg, HISTOGRAMME_TYPE typeHistogramme)
{
    type            =   typeHistogramme ;
    _cimg         =   cimg;
    _data           =   NULL;
    _data_quantity  = 0;
    _data_size      = -1;
}

void Histogramme::generate(){
    //cout << "Histo:gen " << _cimg << " " << _cimg->width() << " " << _cimg->height() << endl;
    _data_quantity = 0;
    if( _data != NULL)
        delete _data;
    int * currentPixel;
    int largeur = _cimg->width();
    int hauteur =  _cimg->height();


    if( type == HISTOGRAMME_HORIZONTAL){
        _data = new int[ largeur];
        _data_size = largeur;
        for(int c = 0; c < largeur ; c++ ){
            _data[c] = 0;
            for(int l = 0 ; l < hauteur ; l++){
                currentPixel = _cimg->data(c,l);
                _data[c]+= (currentPixel[0] + currentPixel[1] + currentPixel[2]) < SEUIL;
            }

            _data_quantity += _data[c];
        }
    }else{
        _data = new int[ hauteur];
        _data_size = hauteur;
        for(int l = 0 ; l < hauteur ; l++){
            _data[l] = 0;
            for(int c = 0; c < largeur ; c++ ){
                currentPixel = _cimg->data(c,l);
                _data[l]+= (currentPixel[0] + currentPixel[1] + currentPixel[2]) < SEUIL;
            }
            _data_quantity += _data[l];

        }

    }

}


float Histogramme::compare(const Histogramme & h){
    //if( h._data_size != _data_size)
    //    return 101.0f;
    int differences = 0;
    for(int i=0; i < _data_size ; i++)
        differences += abs( _data[i] - h._data[i]  );
    return (differences*100)/(h._data_quantity + _data_quantity);
}

Histogramme::~Histogramme()
{
   if( _data != NULL)
        delete _data;
    _data_size = -1;
}

HISTOGRAMME_TYPE        Histogramme::getType(){
    return type;
}


const int *             Histogramme::getData(){
    return _data;
}
int                     Histogramme::getSize(){
    return _data_size;
}


Histogramme::Histogramme(const Histogramme & h)
{
    type = h.type;
    _cimg= h._cimg;
    _data_size = h._data_size;
    if(  _data_size < 0 ){
        _data = new int[_data_size];
        for(int i=0; i < _data_size ; i++)
            _data[i] = h._data[i];

    }else{
        _data = NULL;
    }

}
