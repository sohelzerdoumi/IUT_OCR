#include "Histogramme.h"

#include <stdlib.h>

Histogramme::Histogramme(sf::Image * img, HISTOGRAMME_TYPE typeHistogramme)
: type( typeHistogramme )
{
    _img = img;
    _data = NULL;
}

void Histogramme::generate(){
    int largeur = _img->GetWidth();
    int hauteur = _img->GetHeight();


    if( type == HISTOGRAMME_HORIZONTAL){
        _data = new int[ largeur];
        for(int c = 0; c < largeur ; c++ ){
            _data[c] = 0;
            for(int l = 0 ; l < hauteur ; l++)
                _data[c]+= _img->GetPixel(c,l).r + _img->GetPixel(c,l).g + _img->GetPixel(c,l).b ;
        }
    }else{
        _data = new int[ hauteur];
        for(int l = 0 ; l < hauteur ; l++){
            _data[l] = 0;
            for(int c = 0; c < largeur ; c++ )
                _data[l] += _img->GetPixel(c,l).r + _img->GetPixel(c,l).g + _img->GetPixel(c,l).b ;
        }

    }

}

Histogramme::~Histogramme()
{
   if( _data != NULL)
    delete _data;
}
