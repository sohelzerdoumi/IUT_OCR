#include "MyImage.h"

#include <iostream>

using namespace std;

MyImage::MyImage(std::string filename)
: hHorizontal(this, HISTOGRAMME_HORIZONTAL),hVertical(this, HISTOGRAMME_VERTICAL)
{
    _filename = filename;
    cout << filename<< endl;
    _img.LoadFromFile(filename);
    SetImage(_img);
    generateHistogrammes();

}

MyImage::MyImage(const MyImage & i)
: hHorizontal(this, HISTOGRAMME_HORIZONTAL),hVertical(this, HISTOGRAMME_VERTICAL)
{
    cout << "MyImage::copie" << endl;
    _filename = i._filename;
    _img.LoadFromFile(_filename);
    SetImage(_img);
    generateHistogrammes();
}

float MyImage::compare(const MyImage & i){
    MyImage tmp(i);
    tmp.Resize( 100, 100);
    tmp.GetPixel(0,30);
    //tmp.generateHistogrammes();
    cout << "Compare x : " << tmp.GetSize().x << "  " <<  GetSize().x  << endl;
    cout << "Compare y : " << tmp.GetSize().y << "  " <<  GetSize().y  << endl;

    return 1;
    //return ( hHorizontal.compare(tmp.hHorizontal ) + hVertical.compare(tmp.hVertical ) )/2 ;
}

MyImage::~MyImage(){}


void MyImage::generateHistogrammes(){
    hHorizontal.generate();
    hVertical.generate();
}
