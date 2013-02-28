#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <SFML/Graphics.hpp>
//#include "CImg.h"

#include <string>
#include "Histogramme.h"

class MyImage : public sf::Sprite
{
    public:
        MyImage(const MyImage & i);
        MyImage(std::string filename);
        virtual ~MyImage();

        void generateHistogrammes();
        float compare(const MyImage & i);
    private:
        Histogramme hHorizontal;
        Histogramme hVertical;
        sf::Image       _img;
        std::string     _filename;
};

#endif // MYIMAGE_H
