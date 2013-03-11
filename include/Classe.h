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
        float getCorrespondance(const MyImage & image) const;
        float getCorrespondanceNormal(const MyImage & image) const;
        float getCorrespondanceMean(const MyImage & image) const;
        std::map<std::string, int>  test() const;
    private:
        std::vector<const MyImage *>   _images;
        MyImage *                _image_mean;
        void addImage(const std::string & filename);
        std::string  pathDir;

};

#endif // CLASSE_H
