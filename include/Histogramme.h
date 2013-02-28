#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H
#include <SFML/Graphics.hpp>


enum HISTOGRAMME_TYPE{
    HISTOGRAMME_HORIZONTAL,
    HISTOGRAMME_VERTICAL,
};


class Histogramme
{
    public:
        Histogramme(sf::Image * img, HISTOGRAMME_TYPE typeHistogramme);
        virtual ~Histogramme();
        void generate();

        const HISTOGRAMME_TYPE type;
    private:
        int *       _data;
        sf::Image * _img;
};

#endif // HISTOGRAMME_H
