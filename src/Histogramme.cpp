#include "Histogramme.h"

#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
Histogramme::Histogramme(sf::Sprite * sprite, HISTOGRAMME_TYPE typeHistogramme)
{
    type            =   typeHistogramme ;
    _sprite         =   sprite;
    _data           =   NULL;
    _data_quantity  = 0;
    _data_size      = -1;
}

void Histogramme::generate(){
    cout << "Histo:gen " << _sprite << " " << _sprite->GetSize().x << " " << _sprite->GetSize().y << endl;
    _data_quantity = 0;
    if( _data != NULL)
        delete _data;
    int largeur = _sprite->GetSize().x;
    int hauteur = _sprite->GetSize().y;


    if( type == HISTOGRAMME_HORIZONTAL){
        _data = new int[ largeur];
        _data_size = largeur;
        for(int c = 0; c < largeur ; c++ ){
            _data[c] = 0;
            for(int l = 0 ; l < hauteur ; l++)
                _data[c]+= ( _sprite->GetPixel(c,l).r + _sprite->GetPixel(c,l).g + _sprite->GetPixel(c,l).b ) < SEUIL;

            _data_quantity += _data[c];
        }
    }else{
        _data = new int[ hauteur];
        _data_size = hauteur;
        for(int l = 0 ; l < hauteur ; l++){
            _data[l] = 0;
            for(int c = 0; c < largeur ; c++ )
                _data[l] += (_sprite->GetPixel(c,l).r + _sprite->GetPixel(c,l).g + _sprite->GetPixel(c,l).b ) < SEUIL;

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

Histogramme &        Histogramme::operator=(const Histogramme & h){
    if( _data != NULL)
        delete _data;
    type = h.type;
    _sprite = h._sprite;
    _data_size = h._data_size;
    if(  _data_size < 0 ){
        _data = new int[_data_size];
        for(int i=0; i < _data_size ; i++)
            _data[i] = h._data[i];

    }else{
        _data = NULL;
    }

    return *this;
}


Histogramme::Histogramme(const Histogramme & h)
{
    type = h.type;
    _sprite= h._sprite;
    _data_size = h._data_size;
    if(  _data_size < 0 ){
        _data = new int[_data_size];
        for(int i=0; i < _data_size ; i++)
            _data[i] = h._data[i];

    }else{
        _data = NULL;
    }

}
