#include <dirent.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "OCR.h"

using namespace std;


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
    string pathDir = PATH_BASE;

    std::vector <std::string> dirs =  read_directory( pathDir);
    for(int i = 0; i < (signed)dirs.size() ;i++){
            _classes.push_back( new Classe( dirs[i]) );

    }/*
    currentDir = opendir( pathDir.c_str());

    std::string tmp_dirName;
    while ( (subDir = readdir(currentDir)) !=  NULL ){
        tmp_dirName =subDir->d_name;
        if( tmp_dirName != "." && tmp_dirName  != ".." )
            / Creation /
            _classes.push_back( new Classe( tmp_dirName) );
    }*/
}


Correspondance OCR::getCorrespondance(const MyImage & image) const{
    Correspondance c={0,0};
    float differenceMin = 100000000;
    float tmp_diff = 10000000;
    int   id_diffMin = -1;
    for(int i=0; i < (signed)_classes.size() ;i++){
        tmp_diff = _classes[i]->getCorrespondanceMean(image);
        //cout << _classes[i]->nom << " " << tmp_diff << endl;
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

void  OCR::displayConfusionMatrix() const{
    int success = 0;
    int fail    = 0;
    std::map<string, int> rapport;
    /*
     *  Affichage en-tete tableau
     */
     cout << "    |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9  " << endl;
     cout << "-------------------------------------------------------" << endl;

    /*
     *  Rapport par classe
     */
    for( int i=0; i < (signed)_classes.size() ; i++ ){

        rapport = _classes[i]->test();
        cout << "   " << _classes[i]->nom ;
        for(int j=0; j < 10 ; j++){
             if( rapport.find( intToString(j)) ==rapport.end() ){
                cout << "|  0 " ;
             }else{

                if( _classes[i]->nom == intToString(j) ){
                    success += rapport[intToString(j)];
                    cout << "| " ;
                    cout << "\e[1m\e[32m\e[40m";
                    cout <<  setw(2) ;
                    cout << rapport[intToString(j)] << " ";
                    cout << "\33[0m" ;
                }
                else{
                    fail += rapport[intToString(j)] ;
                    cout << "| " ;
                    cout << "\e[1m\e[32m\e[41m";
                    cout <<  setw(2) ;
                    cout << rapport[intToString(j)] << " ";
                    cout << "\33[0m" ;
                }

             }


        }
        cout << endl;



    }


        cout << "Reconnu : " << success << endl
             << "Non Reconnu : " << fail << endl;

        cout << "Reconnaissance : " << success*100/(success+fail) << " %" << endl;



}


OCR::~OCR()
{
    //dtor
}
