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
    //cout << "MyImage::copie" << endl;
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

void MyImage::crop(){
    int xMin=0, yMin=0, xMax=1000000000, yMax=1000000000;
    const int * tmp_data;

    /*
     * Horizontal
     */
     tmp_data = hHorizontal.getData();
     while(xMin < hHorizontal.getSize()){
        if( tmp_data[xMin] > 0 )
            break;
     xMin++;}

    xMax = hHorizontal.getSize() -1;
    while(xMax >= 0){
        if( tmp_data[xMax] > 0 )
            break;
     xMax--;} xMax++;

    /*
     * Vertical
     */
     tmp_data = hVertical.getData();
     while(yMin < hVertical.getSize()){
        if( tmp_data[yMin] > 0 )
            break;
     yMin++;}

    yMax = hVertical.getSize() -1;
    while(yMax >= 0){
        if( tmp_data[yMax] > 0 )
            break;
     yMax--;} yMax++;

        cout << xMin << " " << yMin << "    " << xMax << " " << yMax << endl;
     _cimg.crop(xMin,yMin,0, xMax,yMax,0);

}

MyImage::~MyImage(){}


void MyImage::generateHistogrammes(){
    hHorizontal.generate();
    hVertical.generate();
    crop();
    hHorizontal.generate();
    hVertical.generate();
}
