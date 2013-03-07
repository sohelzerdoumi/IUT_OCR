#ifndef CLASSE_H
#define CLASSE_H
#include "MyImage.h"
#include <vector>
#include <map>
#include <string>

class Classe
{
    public:
        Classe(const std::string & nomClasse);
        virtual ~Classe();
        const std::string  nom;
        float getCorrespondanceMin(MyImage & image) const;
        std::map<std::string, int>  test() const;
    private:
        std::vector<MyImage *>   _images;
        void addImage(const std::string & filename);
        std::string  pathDir;

};

#endif // CLASSE_H
