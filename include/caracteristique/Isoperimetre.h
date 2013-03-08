#ifndef ISOPERIMETRE_H
#define ISOPERIMETRE_H

#include "Caracteristique.h"


class Isoperimetre : public Caracteristique
{
    public:
        /** Default constructor */
        Isoperimetre(cimg_library::CImg<int>  *  cimg);
        /** Default destructor */
        virtual ~Isoperimetre();
        virtual void                         generate();
};

#endif // ISOPERIMETRE_H
