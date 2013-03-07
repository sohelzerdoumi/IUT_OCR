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
        Vecteur getVector() const;

    private:
        int                     _data_quantity;
        Vecteur                 _vecteur;

    public:
        float                   getPonderation() const ;
        const int *             getData();
        int                     getSize();
        int                     getDataQuantity();

};

#endif // PROFIL_H
