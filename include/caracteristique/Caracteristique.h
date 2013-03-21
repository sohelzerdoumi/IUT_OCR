#ifndef CARACTERISTIQUE_H
#define CARACTERISTIQUE_H
#include "CImg.h"
#include "Vecteur.h"
#include <utils.h>
#include <vector>
#include <string>

/**
 * Une caracteristique est un ensemble de données
 * qui permettent de representer mathematiquement une forme
 */

class Caracteristique
{
    public:
        /** Default constructor */
        Caracteristique(const Caracteristique & c);
        Caracteristique(const std::vector<const Caracteristique*> & caracteristiques);
        Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string & nomCarateristique, const float & ponderationCaracteristique = 1.0f , const int & diff_max = 1000);
        virtual ~Caracteristique();

        const std::string           nom;
        const float                 ponderation;
        const int                   difference_max;
        virtual void                generate();
        virtual float               compare( const Caracteristique * c) const;

        virtual Vecteur             getVector() const;

    protected:
        cimg_library::CImg<int>  *  _cimg;
        Vecteur                 _vecteur;

};

#include "Profil.h"
#include "Zoning.h"
#include "Isoperimetre.h"
#include "Courbure.h"
#include "MomentGeometrique.h"
#endif // CARACTERISTIQUE_H
