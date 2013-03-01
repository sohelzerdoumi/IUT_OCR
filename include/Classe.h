#ifndef CLASSE_H
#define CLASSE_H
#include "MyImage.h"
#include <vector>

class Classe
{
    public:
        Classe(const std::string & nomClasse);
        virtual ~Classe();
        const std::string  nom;
        float getCorrespondanceMin(MyImage & image);
    private:
        std::vector<MyImage *>   _images;
        void addImage(const std::string & filename);

};

#endif // CLASSE_H
