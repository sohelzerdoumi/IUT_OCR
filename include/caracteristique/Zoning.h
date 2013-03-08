#ifndef ZONING_H
#define ZONING_H
#include "Caracteristique.h"

#define ZONING_LARGEUR 5
#define ZONING_HAUTEUR 5
#define ZONING_DIFF_MAX 100

class Zoning : public Caracteristique
{
    public:
        /** Default constructor */
        Zoning(cimg_library::CImg<int>  *  cimg);
        /** Default destructor */
        virtual ~Zoning();
        virtual void                    generate();
    protected:
        double                          _zone[ZONING_LARGEUR][ZONING_HAUTEUR];

};

#endif // ZONING_H
