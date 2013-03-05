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
//    int isoDiff = abs(tmp.hVertical.getDataQuantity() - hVertical.getDataQuantity() );
    //cout << i._filename << " - " << _filename << " = " << isoDiff << endl;
    //return 1;
    return /*( hHorizontal.compare(tmp.hHorizontal ) + hVertical.compare(tmp.hVertical ) )**/compareZoning(i);//*(isoDiff == 0 ? 1 : 1+isoDiff/50) ;
}

float MyImage::compareZoning(const MyImage & i){
    float diff = 0;
      for(int c = 0; c < 3; c++)
        for(int l =0 ; l <3 ; l++)
            diff = abs(_zone[c][l] - i._zone[c][l]);

    return diff;
}


void MyImage::generateZoning(){
    for(int c = 0; c < 3; c++)
        for(int l =0 ; l <3 ; l++)
            _zone[c][l] = _cimg.get_crop( c*_cimg.width()/3, l*_cimg.height()/3 ,0,
                                         (c+1)*_cimg.width()/3 , (l+1)*_cimg.height()/3 ).mean();


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
