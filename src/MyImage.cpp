#include "MyImage.h"

#include <cmath>
#include <iostream>

using namespace cimg_library;
using namespace std;

MyImage::MyImage(std::string filename,int largeur, int hauteur )
: _cimg(filename.c_str())
{
    _filename = filename;
    toBinary();
    _cimg.autocrop(255);
        _cimg.resize(largeur,hauteur);

    loadCaracteristiques();
}

MyImage::MyImage(const MyImage & i, int largeur, int hauteur)
: _cimg(i._filename.c_str())
{
    _filename = i._filename;
    toBinary();
    _cimg.autocrop(255);
    _cimg.resize(largeur,hauteur);
    loadCaracteristiques();
}

MyImage::MyImage(const MyImage & i)
: _cimg( i._filename.c_str())//, hHorizontal(&_cimg, HISTOGRAMME_HORIZONTAL),hVertical(&_cimg, HISTOGRAMME_VERTICAL)
{
    _filename = i._filename;
    toBinary();
    _cimg.autocrop(255);
    loadCaracteristiques();
}

void MyImage::toBinary(){
    int largeur = _cimg.width();
    int hauteur =  _cimg.height();
    int * currentPixel;


    for(int c = 0; c < largeur ; c++ )
        for(int l = 0 ; l < hauteur ; l++){
            currentPixel = _cimg.data(c,l);
            currentPixel[0] = (currentPixel[0] > 200) * 255;
        }

}




float MyImage::compare(const MyImage & img) const{
    //MyImage tmp(i,_cimg.width() , _cimg.height());
    int diff = 0; //( hHorizontal.compare(tmp.hHorizontal ) + hVertical.compare(tmp.hVertical ) );
    for(int i=0; i < (signed)_caracteristiques.size() ; i++)
        diff += _caracteristiques[i]->compare(img._caracteristiques[i]);

    return diff;
}

void MyImage::generateCaracteristiques(){
    for(int i=0; i < (signed)_caracteristiques.size() ; i++)
        _caracteristiques[i]->generate();

}
void MyImage::loadCaracteristiques(){
    _caracteristiques.push_back( new  Histogramme(&_cimg, HISTOGRAMME_HORIZONTAL));
    _caracteristiques.push_back( new  Histogramme(&_cimg, HISTOGRAMME_VERTICAL));
    _caracteristiques.push_back( new  Zoning(&_cimg));


    generateCaracteristiques();
}

void MyImage::display() const{
    _cimg.display();

}

bool MyImage::operator==(const MyImage & i) const{
    return _filename == i._filename;
}


MyImage::~MyImage(){
    for(int i=0; i < (signed)_caracteristiques.size() ; i++)
        delete _caracteristiques[i];

}
