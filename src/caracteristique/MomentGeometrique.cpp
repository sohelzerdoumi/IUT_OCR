#include <caracteristique/MomentGeometrique.h>

MomentGeometrique::MomentGeometrique(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "moment_geometrique" ,
                     getConfigValueFloat("ocr.caracteristique.defaut.momentgeometrique.ponderation"),
                     getConfigValueInt("ocr.caracteristique.defaut.momentgeometrique.diff_max"))
{
}

MomentGeometrique::~MomentGeometrique(){}

void MomentGeometrique::generate(){
    _vecteur.clear();

    int * currentPixel;
    int surface = 0;
    float hauteur_moyenne = 0;
    float largeur_moyenne = 0;

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

    hauteur_moyenne = (hauteur_moyenne/surface) *100.0f/hauteur ;
    largeur_moyenne = (largeur_moyenne/surface) *100.0f/largeur ;

    _vecteur.push_back(hauteur_moyenne);
    _vecteur.push_back(largeur_moyenne);
}
