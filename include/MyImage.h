#ifndef MYIMAGE_H
#define MYIMAGE_H
#include "CImg.h"

#include <string>
#include "Histogramme.h"
#define ZONING_LARGEUR 3
#define ZONING_HAUTEUR 3
#define ZONING_DIFF_MAX 100


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
        double                          _zone[ZONING_LARGEUR][ZONING_HAUTEUR];
        cimg_library::CImg<int>        _cimg;
        Histogramme hHorizontal;
        Histogramme hVertical;
        std::string                 _filename;
        void                        toBinary();
};

#endif // MYIMAGE_H
