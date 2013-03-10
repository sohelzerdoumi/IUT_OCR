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

    private:
        int                     _data_quantity;

    public:
        const int *             getData();
        int                     getSize();
        int                     getDataQuantity();

};

#endif // PROFIL_H