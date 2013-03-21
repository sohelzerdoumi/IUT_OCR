#include "caracteristique/Caracteristique.h"

using namespace std;

Caracteristique::Caracteristique(cimg_library::CImg<int>  *  cimg, const std::string & nomCaracteristique, const float & ponderationCaracteristique, const int & diff_max)
: nom( nomCaracteristique),   ponderation( ponderationCaracteristique) , difference_max( diff_max), _cimg( cimg)
{
}

Caracteristique::Caracteristique(const std::vector<const Caracteristique*> & caracteristiques)
: nom( (caracteristiques.size() > 0) ? caracteristiques[0]->nom : "NaN" ) , 
  ponderation( (caracteristiques.size() > 0) ? caracteristiques[0]->ponderation : 1.0f ),
  difference_max( (caracteristiques.size() > 0) ? caracteristiques[0]->difference_max : 1000 )
{
    if( caracteristiques.size() == 0)
        return;
    vector<const Vecteur *> vecteurs;


    for(int idCaracteristique = 0; idCaracteristique < (signed)caracteristiques.size() ; idCaracteristique++)
        vecteurs.push_back( &caracteristiques[idCaracteristique]->_vecteur );

    _vecteur = Vecteur( vecteurs );
}


Caracteristique::Caracteristique(const Caracteristique & c)
: nom( c.nom), ponderation( c.ponderation ), difference_max(c.difference_max), _cimg( c._cimg), _vecteur( c._vecteur)
{}

Caracteristique::~Caracteristique() {}

void   Caracteristique::generate(){}

float       Caracteristique::compare( const Caracteristique * c) const{
    return getVector().compare(c->getVector() , difference_max);
}

Vecteur       Caracteristique::getVector() const{
    return _vecteur;
}
