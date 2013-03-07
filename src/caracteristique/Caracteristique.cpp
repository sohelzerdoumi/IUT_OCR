#include "caracteristique/Caracteristique.h"

Caracteristique::Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string nomCaracteristique)
: nom( nomCaracteristique) , _cimg( cimg)
{
}


Caracteristique::Caracteristique(const Caracteristique & c)
: nom( c.nom) , _cimg( c._cimg)
{
//    generate();
}

Caracteristique::~Caracteristique()
{
    //dtor
}


float       Caracteristique::compare( const Caracteristique * c) const{
    return getVector().compare(c->getVector(), getPonderation() );
}
