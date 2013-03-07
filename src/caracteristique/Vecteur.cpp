#include "caracteristique/Vecteur.h"
#include <cmath>
#include <iostream>


using namespace std;


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
    distance = sqrt(distance);

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
