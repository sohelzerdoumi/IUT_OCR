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
        float compareZoning(const MyImage & i);
        void    generateZoning();
        void display();
    private:
        double                          _zone[3][3];
        cimg_library::CImg<int>        _cimg;
        Histogramme hHorizontal;
        Histogramme hVertical;
        std::string                 _filename;
        void                        toBinary();
};

#endif // MYIMAGE_H
