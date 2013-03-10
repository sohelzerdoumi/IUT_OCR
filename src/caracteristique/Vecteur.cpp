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

float Vecteur::compare( const std::vector<float> & vec, float ponderation ) const{
    string mode = getConfigValueString("ocr.vecteur.mode");
    if( mode == "euclide")
        return compareEuclidienne(vec, ponderation);

    if( mode == "manhattan")
        return compareEuclidienne(vec, ponderation);
    return compareMinkowski(vec);
}


float Vecteur::compareManhattan( const std::vector<float> & vec, float ponderation ) const{
    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    float distance = 0;
    for(int i=0; i < (signed) this->size() ; i++){
        distance += abs(vec[i] - (*this)[i])*ponderation;
    }

    return distance;
}
float Vecteur::compareEuclidienne( const std::vector<float> & vec, float ponderation ) const{
    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    float distance = 0;
    for(int i=0; i < (signed) this->size() ; i++){
        if(pow(abs(vec[i] - (*this)[i]) , 2) >155*155)
            return VECTOR_ERROR;

        distance += pow(abs(vec[i] - (*this)[i]) , 2)*ponderation;
    }
    distance = sqrt(distance)/this->size() ;
    return distance;
}


float Vecteur::compareMinkowski( const std::vector<float> & vec, float ponderation ) const{
    mpz_class distance = 0;
    mpz_class tmpz = 0;

    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    for(int i=0; i < (signed) this->size() ; i++){
        mpz_ui_pow_ui( tmpz.get_mpz_t(),  abs(vec[i] - (*this)[i]),  this->size());
        distance += tmpz;
    }

    distance = pow( distance , 1.0f/this->size() );
    return distance;

}
