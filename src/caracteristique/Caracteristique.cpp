#include "caracteristique/Caracteristique.h"

Caracteristique::Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string & nomCaracteristique, const float & ponderationCaracteristique)
: nom( nomCaracteristique), ponderation( ponderationCaracteristique) , _cimg( cimg)
{
}


Caracteristique::Caracteristique(const Caracteristique & c)
: nom( c.nom), ponderation( c.ponderation ), _cimg( c._cimg)
{
//    generate();
}

Caracteristique::~Caracteristique()
{
    //dtor
}


float       Caracteristique::compare( const Caracteristique * c) const{
    return getVector().compare(c->getVector(), ponderation );
}

Vecteur       Caracteristique::getVector() const{
    return _vecteur;
}
