#include "MyImage.h"

#include <iostream>

using namespace cimg_library;
using namespace std;

MyImage::MyImage(std::string filename)
: _cimg(filename.c_str()), hHorizontal(&_cimg, HISTOGRAMME_HORIZONTAL),hVertical(&_cimg, HISTOGRAMME_VERTICAL)
{
    _filename = filename;
    generateHistogrammes();

}

MyImage::MyImage(const MyImage & i)
: _cimg( i._filename.c_str()), hHorizontal(&_cimg, HISTOGRAMME_HORIZONTAL),hVertical(&_cimg, HISTOGRAMME_VERTICAL)
{
    cout << "MyImage::copie" << endl;
    _filename = i._filename;
    generateHistogrammes();
}

float MyImage::compare(const MyImage & i){
    MyImage tmp(i);
    tmp._cimg.resize( _cimg.width() , _cimg.height() );
    tmp.generateHistogrammes();
    //return 1;
    return ( hHorizontal.compare(tmp.hHorizontal ) + hVertical.compare(tmp.hVertical ) )/2 ;
}

MyImage::~MyImage(){}


void MyImage::generateHistogrammes(){
    hHorizontal.generate();
    hVertical.generate();
}
