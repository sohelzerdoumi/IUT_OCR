#include <dirent.h>
#include <string>
#include <iostream>

using namespace std;

#include "OCR.h"

OCR * OCR::_instance = NULL;

OCR * OCR::instance(){
    if( _instance == NULL)
        _instance = new OCR();

    return _instance;
}

OCR::OCR()
{
    /*
     * On parcourt le repertoire PATH_BASE
     * On créé les Classes a partir du nom de ces sous repertoires
     */
    DIR	*  currentDir;
    struct dirent *	subDir;
    string pathDir = PATH_BASE  ;
    currentDir = opendir( pathDir.c_str());

    std::string tmp_dirName;
    while ( (subDir = readdir(currentDir)) !=  NULL ){
        tmp_dirName =subDir->d_name;
        if( tmp_dirName != "." && tmp_dirName  != ".." )
            /* Creation */
            _classes.push_back( new Classe( tmp_dirName) );
    }
}

OCR::~OCR()
{
    //dtor
}
