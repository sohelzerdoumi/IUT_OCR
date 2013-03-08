#include <caracteristique/MomentGeometrique.h>
#define PONDERATION_MOMENT_GEOMETRIQUE 1.0f

MomentGeometrique::MomentGeometrique(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "MOMENT_GEOMETRIQUE" , PONDERATION_MOMENT_GEOMETRIQUE)
{
}

MomentGeometrique::~MomentGeometrique(){}

void MomentGeometrique::generate(){
    _vecteur.clear();

    int * currentPixel;
    int surface = 0;
    int hauteur_moyenne = 0;
    int largeur_moyenne = 0;

    int largeur = _cimg->width();
    int hauteur =  _cimg->height();

    for(int c = 0; c < largeur ; c++ ){
        for(int l = 0 ; l < hauteur ; l++){
            currentPixel = _cimg->data(c,l);
            if(currentPixel[0]  < 200 ){
                surface++;
                hauteur_moyenne += l;
                largeur_moyenne += c;

            }
        }
    }

    hauteur_moyenne /= surface;
    largeur_moyenne /= surface;

    _vecteur.push_back(hauteur_moyenne);
    _vecteur.push_back(largeur_moyenne);
}
