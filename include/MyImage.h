#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <SFML/Graphics.hpp>
#include "Histogramme.h"

class MyImage : public sf::Image
{
    public:
        MyImage(std::string filename);
        virtual ~MyImage();

        void generateHistogrammes();
    private:
        Histogramme hHorizontal;
        Histogramme hVertical;
};

#endif // MYIMAGE_H
