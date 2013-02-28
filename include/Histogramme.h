#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H
#include "CImg.h"
#define SEUIL 220*3

enum HISTOGRAMME_TYPE{
    HISTOGRAMME_HORIZONTAL,
    HISTOGRAMME_VERTICAL,
};


class Histogramme
{
    public:
        Histogramme(const Histogramme & h);
        Histogramme(cimg_library::CImg<int>  *  cimg, HISTOGRAMME_TYPE typeHistogramme);
        virtual ~Histogramme();
        void generate();
        float compare(const Histogramme & h);

    private:
        HISTOGRAMME_TYPE        type;
        int                     _data_quantity;
        int                     _data_size;
        int *                   _data;
        cimg_library::CImg<int>  *  _cimg;

    public:
        HISTOGRAMME_TYPE        getType();

};

#endif // HISTOGRAMME_H
