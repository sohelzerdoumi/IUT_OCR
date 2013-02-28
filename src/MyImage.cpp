#include "MyImage.h"

MyImage::MyImage(std::string filename)
: hHorizontal(this, HISTOGRAMME_HORIZONTAL),hVertical(this, HISTOGRAMME_VERTICAL)
{
    LoadFromFile(filename);
    generateHistogrammes();
}

MyImage::~MyImage()
{
    //dtor
}


void MyImage::generateHistogrammes(){
    hHorizontal.generate();
    hVertical.generate();
}
