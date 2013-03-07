#include <dirent.h>
#include <iostream>

#include "Classe.h"
#include "OCR.h"

using namespace std;

Classe::Classe(const std::string & nomClasse)
: nom ( nomClasse)
{
    DIR	*  currentDir;
    struct dirent *	subDir;
            pathDir = PATH_BASE;
            pathDir += "/";
            pathDir += nom  ;
    currentDir = opendir( pathDir.c_str());

    std::string tmp_dirName;
    while ( (subDir = readdir(currentDir)) !=  NULL ){
        tmp_dirName =subDir->d_name;
        if( tmp_dirName != "." && tmp_dirName  != ".." )
            addImage(tmp_dirName);
    }

}

Classe::~Classe(){}

float Classe::getCorrespondanceMin(MyImage & image) const{
    float correspondance = 10000000;
    float tmp_corresp = 10000000;
    for(int i=0; i < (signed)_images.size() ;i++){
        if( !(image == *_images[i]) ){
            tmp_corresp = _images[i]->compare(image);
            correspondance = ( tmp_corresp < correspondance ) ? tmp_corresp : correspondance;
        }

    }

    return correspondance;
}

void Classe::addImage(const std::string & filename){
    MyImage * image = new MyImage( pathDir + "/" + filename );
    _images.push_back( image);

}

map<string,int>   Classe::test() const{
    map<string,int> rapport;
    string nomClasse;
    for(int i=0; i <  (signed)_images.size() ;i++){
        nomClasse = OCR::instance()->getCorrespondance( *_images[i]).classe->nom;
        if( rapport.find(nomClasse) != rapport.end())
            rapport[nomClasse]++;
        else
            rapport[nomClasse]=1;
    }

    return rapport;
}
