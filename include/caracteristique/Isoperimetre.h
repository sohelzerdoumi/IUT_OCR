#ifndef ISOPERIMETRE_H
#define ISOPERIMETRE_H

#include "Caracteristique.h"

/**
 * Le rapport isoperimetre consiste a calculer le rapport entre :
 *   - la surface : tous les pixels noirs
 *   - le périmètre : les pixels formant le contour de la forme
 */

class Isoperimetre : public Caracteristique
{
    public:
        Isoperimetre(cimg_library::CImg<int>  *  cimg);
        virtual ~Isoperimetre();

        virtual void                         generate();
};

#endif // ISOPERIMETRE_H
