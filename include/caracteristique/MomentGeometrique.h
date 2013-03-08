#ifndef MOMENTGEOMETRIQUE_H
#define MOMENTGEOMETRIQUE_H

#include "Caracteristique.h"


class MomentGeometrique : public Caracteristique
{
    public:
        MomentGeometrique(cimg_library::CImg<int>  *  cimg);
        virtual ~MomentGeometrique();
        virtual void                         generate();

};

#endif // MOMENTGEOMETRIQUE_H
