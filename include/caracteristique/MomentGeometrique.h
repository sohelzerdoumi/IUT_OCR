#ifndef MOMENTGEOMETRIQUE_H
#define MOMENTGEOMETRIQUE_H

#include "Caracteristique.h"

/**
 * Le moment géometrique représente le centre de gravité de la forme
 */

class MomentGeometrique : public Caracteristique
{
    public:
        MomentGeometrique(cimg_library::CImg<int>  *  cimg);
        virtual ~MomentGeometrique();
        virtual void                         generate();

};

#endif // MOMENTGEOMETRIQUE_H
