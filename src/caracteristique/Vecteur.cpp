#include "caracteristique/Vecteur.h"
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
    return compareEuclidienne(vec, ponderation);
    //return compareMinkowski(vec);
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
    if( vec.size() != this->size() )
        return VECTOR_ERROR;

    float distance = 0;
    for(int i=0; i < (signed) this->size() ; i++){
        distance += pow(abs(vec[i] - (*this)[i]) , this->size())*ponderation;
    }

    distance = pow( distance , 1.0f/this->size() );
    return distance;

}
