#include "caracteristique/Courbure.h"

#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cimg_library;


Courbure::Courbure(cimg_library::CImg<int>  *  cimg)
: Caracteristique( cimg , "courbure", 
                  getConfigValueFloat("ocr.caracteristique.defaut.courbure.ponderation") ,
                  getConfigValueInt("ocr.caracteristique.defaut.courbure.diff_max") )

{
}

void Courbure::generate(){
    _vecteur.clear();
    int currentPixel;
    int cpt;
    int largeur = _cimg->width();
    int hauteur =  _cimg->height();

    /*
     *  Courbure Haut
     */
    for(int idColonne = 0; idColonne < largeur ; idColonne++){
        cpt =0;
        currentPixel = _cimg->data(idColonne,cpt)[0];
        while( currentPixel > SEUIL && cpt < hauteur ) cpt++;

        _vecteur.push_back( cpt );
    }


    /*
     *  Courbure Bas
     */
    for(int idColonne = 0; idColonne < largeur ; idColonne++){
        cpt = hauteur -1;
        currentPixel = _cimg->data(idColonne,cpt)[0];
        while( currentPixel > SEUIL && cpt >= 0 ) cpt--;
        _vecteur.push_back( cpt );
    }


    /*
     *  Courbure Gauche
     */
    for(int idLigne = 0; idLigne < hauteur ; idLigne++){
        cpt = 0;
        currentPixel = _cimg->data(cpt,idLigne)[0];
        while( currentPixel > SEUIL && cpt < largeur ) cpt++;
        _vecteur.push_back( cpt );
    }


    /*
     *  Courbure Droite
     */
    for(int idLigne = 0; idLigne < hauteur ; idLigne++){
        cpt = largeur - 1;
        currentPixel = _cimg->data(cpt,idLigne)[0];
        while( currentPixel > SEUIL && cpt >= 0 ) cpt--;
        _vecteur.push_back( cpt );
    }

}

Courbure::~Courbure() {}


