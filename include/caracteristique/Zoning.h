#ifndef ZONING_H
#define ZONING_H
#include "Caracteristique.h"

#define ZONING_LARGEUR 4
#define ZONING_HAUTEUR 4
#define ZONING_DIFF_MAX 100

class Zoning : public Caracteristique
{
    public:
        /** Default constructor */
        Zoning(cimg_library::CImg<int>  *  cimg);
        /** Default destructor */
        virtual ~Zoning();
        virtual void                    generate();
        virtual Vecteur                 getVector() const;
    protected:
        double                          _zone[ZONING_LARGEUR][ZONING_HAUTEUR];
        inline float                    getPonderation() const ;

};

#endif // ZONING_H
