#include "caracteristique/Vecteur.h"
#include "utils.h"
#include "gmpxx.h"
#include <cmath>
#include <iostream>

using namespace std;

Vecteur::Vecteur(): vector() {}

Vecteur::Vecteur(const Vecteur & v): vector(v) {}

Vecteur::Vecteur( const std::vector<const Vecteur*> vecteurs): vector(){
    if( vecteurs.size() == 0)
        return;
    float tmp_val;

    for(int idCase=0; idCase < (signed)vecteurs[0]->size() ; idCase++ ){
        tmp_val = 0;
        for(int idVecteur = 0; idVecteur < (signed)vecteurs.size() ; idVecteur++ )
            tmp_val += ( *vecteurs[idVecteur] )[idCase];
        this->push_back( tmp_val / (signed)vecteurs.size() );

    }
}


float Vecteur::compare( const std::vector<float> & vec , const int & difference_max) const{
    string mode = getConfigValueString("ocr.vecteur.mode");
    if( mode == "euclide")
        return compareEuclidienne(vec,difference_max);

    if( mode == "manhattan")
        return compareManhattan(vec,difference_max);

    if( mode == "minkowski")
        return compareMinkowski(vec,difference_max);
    return 0;
}


float Vecteur::compareManhattan( const std::vector<float> & vec  , const int & difference_max) const{
    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    float distance = 0;

    auto my_value    = this->begin();
    auto other_value = vec.begin();

    while( my_value != this->end() && other_value != vec.end() ){
        if( abs( *other_value - *my_value ) > difference_max)
            return VECTOR_ERROR;
        distance += abs(*other_value - *my_value);
    }

    return distance;
}
float Vecteur::compareEuclidienne( const std::vector<float> & vec , const int & difference_max ) const{
    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    auto my_value    = this->begin();
    auto other_value = vec.begin();

    float distance = 0;
    while( my_value != this->end() && other_value != vec.end() ){
        if(pow(abs( *other_value - *my_value) , 2) > difference_max*difference_max)
            return VECTOR_ERROR;

        distance += pow(abs( *other_value - *my_value) , 2);
        my_value++; other_value++;
    }

    distance /= this->size() ;
    distance = sqrt(distance) ;
    return distance;
}


float Vecteur::compareMinkowski( const std::vector<float> & vec , const int & difference_max ) const{
    mpz_class distance = 0;
    mpz_class tmpz = 0;

    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    auto my_value    = this->begin();
    auto other_value = vec.begin();

    while( my_value != this->end() && other_value != vec.end() ){
        mpz_ui_pow_ui( tmpz.get_mpz_t(),  abs(other_value - my_value),  this->size());
        distance += tmpz;
    }

    mpz_root( distance.get_mpz_t() , distance.get_mpz_t() ,this->size() );
    return distance.get_si();
}
