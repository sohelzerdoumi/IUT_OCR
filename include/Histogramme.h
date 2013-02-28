#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H
#include <SFML/Graphics.hpp>
#define SEUIL 200*3

enum HISTOGRAMME_TYPE{
    HISTOGRAMME_HORIZONTAL,
    HISTOGRAMME_VERTICAL,
};


class Histogramme
{
    public:
        Histogramme(const Histogramme & h);
        Histogramme(sf::Sprite * img, HISTOGRAMME_TYPE typeHistogramme);
        virtual ~Histogramme();
        void generate();
        float compare(const Histogramme & h);

    private:
        HISTOGRAMME_TYPE        type;
        int                     _data_quantity;
        int                     _data_size;
        int *                   _data;
        sf::Sprite *             _sprite;

    public:
        HISTOGRAMME_TYPE        getType();
        Histogramme &           operator=(const Histogramme & h);

};

#endif // HISTOGRAMME_H
