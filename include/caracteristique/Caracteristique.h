#ifndef CARACTERISTIQUE_H
#define CARACTERISTIQUE_H
#include "CImg.h"
#include "Vecteur.h"
#include <string>

class Caracteristique
{
    public:
        /** Default constructor */
        Caracteristique(const Caracteristique & c);
        Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string nomCarateristique);
        virtual ~Caracteristique();

        const std::string           nom;
        virtual void                generate() = 0;
        virtual float               compare( const Caracteristique * c) const;
        virtual Vecteur             getVector() const =0;
        virtual float               getPonderation() const =0;
    protected:
        cimg_library::CImg<int>  *  _cimg;

};

#include "Profil.h"
#include "Zoning.h"
#endif // CARACTERISTIQUE_H
