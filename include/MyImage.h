#ifndef MYIMAGE_H
#define MYIMAGE_H

#define IMG_HAUTEUR 30
#define IMG_LARGEUR 30
#include <SFML/Graphics.hpp>

#include "CImg.h"

#include <string>
#include <vector>
#include "caracteristique/Caracteristique.h"



class MyImage
{
    public:
        MyImage(const MyImage & i);
        MyImage(const sf::Image & i);
        MyImage(const std::vector<const MyImage*> & images);
        MyImage(const MyImage & i,int largeur = IMG_LARGEUR, int hauteur = IMG_HAUTEUR);
        MyImage(std::string filename,int largeur = IMG_LARGEUR, int hauteur = IMG_HAUTEUR);
        virtual ~MyImage();

        bool operator==(const MyImage & i) const;
        float compare(const MyImage & img, const std::string & classeName = "") const;
        std::string                 getMD5() const;
        void display() const;
        cimg_library::CImg<int>        _cimg;
        inline std::string                     getFilename() const { return _filename; };
    private:
        std::vector<Caracteristique *>  _caracteristiques;
        void                        generateCaracteristiques();
        void                        loadCaracteristiques();
//        Histogramme hHorizontal;
//        Histogramme hVertical;
        std::string                 _filename;
        void                        toBinary();
};

#endif // MYIMAGE_H
