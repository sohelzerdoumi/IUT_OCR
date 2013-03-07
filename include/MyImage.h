#ifndef MYIMAGE_H
#define MYIMAGE_H
#include "CImg.h"

#include <string>
#include <vector>
#include "caracteristique/Caracteristique.h"



class MyImage
{
    public:
        MyImage(const MyImage & i);
        MyImage(const MyImage & i,int largeur, int hauteur);
        MyImage(std::string filename);
        virtual ~MyImage();

        float compare(const MyImage & i);
        void display();
    private:
        std::vector<Caracteristique *>  _caracteristiques;
        void                        generateCaracteristiques();
        void                        loadCaracteristiques();
        cimg_library::CImg<int>        _cimg;
//        Histogramme hHorizontal;
//        Histogramme hVertical;
        std::string                 _filename;
        void                        toBinary();
};

#endif // MYIMAGE_H
