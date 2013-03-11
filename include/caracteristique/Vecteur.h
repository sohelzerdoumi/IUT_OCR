#ifndef VECTEUR_H
#define VECTEUR_H
#define VECTOR_ERROR 1000000
#include <vector>


class Vecteur : public std::vector<float>
{
    public:
        Vecteur();
        Vecteur(const Vecteur & v);
        Vecteur( const std::vector<const Vecteur*> vecteurs);
        float compare( const std::vector<float> & vec ) const;
    protected:
        float compareManhattan( const std::vector<float> & vec) const;
        float compareEuclidienne( const std::vector<float> & vec) const;
        float compareMinkowski( const std::vector<float> & vec ) const;
};

#endif // VECTEUR_H
