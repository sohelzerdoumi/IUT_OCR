#include "MyImage.h"

#include <cmath>
#include <iostream>

using namespace cimg_library;
using namespace std;

MyImage::MyImage(std::string filename)
: _cimg(filename.c_str()), hHorizontal(&_cimg, HISTOGRAMME_HORIZONTAL),hVertical(&_cimg, HISTOGRAMME_VERTICAL)
{
    _filename = filename;
    toBinary();
    //_cimg.erode(1,1);
    generateZoning();
    generateHistogrammes();
    //cout << _cimg.variance()<< endl;;
    //_cimg.display();

}

MyImage::MyImage(const MyImage & i)
: _cimg( i._filename.c_str()), hHorizontal(&_cimg, HISTOGRAMME_HORIZONTAL),hVertical(&_cimg, HISTOGRAMME_VERTICAL)
{
    _filename = i._filename;
    toBinary();
    generateZoning();
    generateHistogrammes();
}

void MyImage::toBinary(){
    int largeur = _cimg.width();
    int hauteur =  _cimg.height();
    int * currentPixel;


    for(int c = 0; c < largeur ; c++ )
        for(int l = 0 ; l < hauteur ; l++){
            currentPixel = _cimg.data(c,l);
            currentPixel[0] = (currentPixel[0] > SEUIL) * 255;
        }

}




float MyImage::compare(const MyImage & i){
    MyImage tmp(i);
    tmp._cimg.resize( _cimg.width() , _cimg.height() );
    tmp.toBinary();
    tmp.generateZoning();
    tmp.generateHistogrammes();

    int diffHistogramme = ( hHorizontal.compare(tmp.hHorizontal ) + hVertical.compare(tmp.hVertical ) );


    return diffHistogramme;//*compareZoning(i);//*(isoDiff == 0 ? 1 : 1+isoDiff/50) ;
}

float MyImage::compareZoning(const MyImage & i){
    float diff = 0;
      for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l <ZONING_HAUTEUR ; l++)
            diff += abs(_zone[c][l] - i._zone[c][l]);
    //cout << diff << endl;
    if( diff > (ZONING_LARGEUR*ZONING_HAUTEUR)*ZONING_DIFF_MAX )
        diff= 100000;
    return diff;
}


void MyImage::generateZoning(){
    int largeur = _cimg.width()/ZONING_LARGEUR-1;
    int hauteur = _cimg.height()/ZONING_HAUTEUR-1;
    for(int c = 0; c < ZONING_LARGEUR; c++)
        for(int l =0 ; l < ZONING_HAUTEUR ; l++)
            _zone[c][l] = _cimg.get_crop( c*largeur, l*hauteur ,0,
                                         (c+1)*largeur , (l+1)*hauteur,0 ).mean();


}

void MyImage::display(){
    _cimg.display();

}

MyImage::~MyImage(){}


void MyImage::generateHistogrammes(){
    _cimg.autocrop(255);
    hHorizontal.generate();
    hVertical.generate();
}
