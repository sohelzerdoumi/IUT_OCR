#ifndef COURBURE_H
#define COURBURE_H

#include "Caracteristique.h"

/**
 * Une courbe représente la forme prise par les 4 cotés (haut, bas, gauche et droite) d'objet
 * Un peu comme un moule que l'on applique d'un coté de l'objet
 */

class Courbure : public Caracteristique
{
    public:
        Courbure(const Courbure & h);
        Courbure(cimg_library::CImg<int>  *  cimg);
        virtual ~Courbure();
        void generate();



};

#endif // COURBURE_H
