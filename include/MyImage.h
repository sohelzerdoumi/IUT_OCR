#ifndef MYIMAGE_H
#define MYIMAGE_H
#include "CImg.h"

#include <string>
#include "Histogramme.h"

class MyImage
{
    public:
        MyImage(const MyImage & i);
        MyImage(std::string filename);
        virtual ~MyImage();

        void generateHistogrammes();
        float compare(const MyImage & i);
    private:
        cimg_library::CImg<int>        _cimg;
        Histogramme hHorizontal;
        Histogramme hVertical;
        std::string                 _filename;
};

#endif // MYIMAGE_H
