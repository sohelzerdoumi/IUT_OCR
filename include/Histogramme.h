#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H
#include "CImg.h"
#define SEUIL 200*3

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
        const int *             getData();
        int                     getSize();

};

#endif // HISTOGRAMME_H
