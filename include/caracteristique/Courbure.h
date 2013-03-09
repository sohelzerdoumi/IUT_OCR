#ifndef COURBURE_H
#define COURBURE_H

#include "Caracteristique.h"


class Courbure : public Caracteristique
{
    public:
        Courbure(const Courbure & h);
        Courbure(cimg_library::CImg<int>  *  cimg);
        virtual ~Courbure();
        void generate();



};

#endif // COURBURE_H
