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
            /** Creation **/
            _classes.push_back( new Classe( tmp_dirName) );
    }
}


Correspondance OCR::getCorrespondance(MyImage & image){
    Correspondance c={0,0};
    float differenceMin = 100000000;
    float tmp_diff = 10000000;
    int   id_diffMin = -1;
    for(int i=0; i < (signed)_classes.size() ;i++){
        tmp_diff = _classes[i]->getCorrespondanceMin(image);
        cout << _classes[i]->nom << " " << tmp_diff << endl;
        if( tmp_diff < differenceMin  ){
            differenceMin = tmp_diff;
            id_diffMin = i;
        }
    }

    if( id_diffMin != -1){
        c.diffMin = differenceMin;
        c.classe  = _classes[id_diffMin];
    }

    return c;
}

OCR::~OCR()
{
    //dtor
}
