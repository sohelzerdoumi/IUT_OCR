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

float Classe::getCorrespondanceMin(MyImage & image){
    float correspondance = 10000000;
    float tmp_corresp = 10000000;
    for(int i=0; i < (signed)_images.size() ;i++){
        tmp_corresp = _images[i]->compare(image);

        correspondance = ( tmp_corresp < correspondance ) ? tmp_corresp : correspondance;
    }

    return correspondance;
}

void Classe::addImage(const std::string & filename){
    MyImage * image = new MyImage( pathDir + "/" + filename );
    _images.push_back( image);

}
