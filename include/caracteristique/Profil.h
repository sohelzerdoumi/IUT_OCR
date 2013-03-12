#ifndef PROFIL_H
#define PROFIL_H

#include "Caracteristique.h"
#define SEUIL 200


class Profil : public Caracteristique
{
    public:
        Profil(const Profil & h);
        Profil(cimg_library::CImg<int>  *  cimg);
        virtual ~Profil();
        void generate();


};

#endif // PROFIL_H
