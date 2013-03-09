#ifndef ZONING_H
#define ZONING_H
#include "Caracteristique.h"



class Zoning : public Caracteristique
{
    public:
        /** Default constructor */
        Zoning(cimg_library::CImg<int>  *  cimg);
        /** Default destructor */
        virtual ~Zoning();
        virtual void                    generate();

};

#endif // ZONING_H
