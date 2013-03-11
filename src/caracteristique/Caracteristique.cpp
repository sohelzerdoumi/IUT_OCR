#include "caracteristique/Caracteristique.h"

using namespace std;

Caracteristique::Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string & nomCaracteristique, const float & ponderationCaracteristique)
: nom( nomCaracteristique), ponderation( ponderationCaracteristique) , _cimg( cimg)
{
}

Caracteristique::Caracteristique(const std::vector<const Caracteristique*> & caracteristiques)
: ponderation( (caracteristiques.size() > 0) ? caracteristiques[0]->ponderation : 1.0f )
{
    if( caracteristiques.size() == 0)
        return;
    vector<const Vecteur *> vecteurs;


    for(int idCaracteristique = 0; idCaracteristique < (signed)caracteristiques.size() ; idCaracteristique++)
        vecteurs.push_back( &caracteristiques[idCaracteristique]->_vecteur );

    _vecteur = Vecteur( vecteurs );
}


Caracteristique::Caracteristique(const Caracteristique & c)
: nom( c.nom), ponderation( c.ponderation ), _cimg( c._cimg), _vecteur( c._vecteur)
{}

Caracteristique::~Caracteristique()
{
    //dtor
}

void   Caracteristique::generate(){}

float       Caracteristique::compare( const Caracteristique * c) const{
    return getVector().compare(c->getVector() );
}

Vecteur       Caracteristique::getVector() const{
    return _vecteur;
}
