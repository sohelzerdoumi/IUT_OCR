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
        Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string & nomCarateristique, const float & ponderationCaracteristique = 1.0f );
        virtual ~Caracteristique();

        const std::string           nom;
        const float                 ponderation;
        virtual void                generate() = 0;
        virtual float               compare( const Caracteristique * c) const;

        virtual Vecteur             getVector() const;

    protected:
        cimg_library::CImg<int>  *  _cimg;
        Vecteur                 _vecteur;

};

#include "Profil.h"
#include "Zoning.h"
#include "Isoperimetre.h"
#include "caracteristique/MomentGeometrique.h"
#endif // CARACTERISTIQUE_H
