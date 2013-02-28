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
    string  pathDir = PATH_BASE;
            pathDir += "/";
            pathDir += nom  ;
    currentDir = opendir( pathDir.c_str());

    std::string tmp_dirName;
    while ( (subDir = readdir(currentDir)) !=  NULL ){
        tmp_dirName =subDir->d_name;
        if( tmp_dirName != "." && tmp_dirName  != ".." )
            loadImage(tmp_dirName);
    }
}

Classe::~Classe(){}


void Classe::loadImage(const std::string & filename){
    string imageFilename =  PATH_BASE;
            imageFilename += "/";
            imageFilename += nom  ;
            imageFilename += "/"  ;
            imageFilename += filename  ;


    MyImage * image = new MyImage( imageFilename );
    _images.push_back( image);
}
