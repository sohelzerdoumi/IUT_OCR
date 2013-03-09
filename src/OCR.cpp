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

    }

}


Correspondance OCR::getCorrespondance(const MyImage & image) const{
    Correspondance c={0,""};
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
        c.nomClasse  =  (differenceMin < getConfigValueInt("ocr.difference_max") ) ? _classes[id_diffMin]->nom : "?";
    }

    return c;
}

void  OCR::displayConfusionMatrix() const{
    int success = 0;
    int fail    = 0;
    int nonReconnu = 0;
    std::map<string, int> rapport;
    /*
     *  Affichage en-tete tableau
     */
     cout << "    |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9  |  ?" << endl;
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

                            nonReconnu += rapport["?"] ;
                            cout << "| " ;
                            cout << "\e[1m\e[32m\e[44m";
                            cout <<  setw(2) ;
                            cout << rapport["?"] << " ";
                            cout << "\33[0m" ;




        cout << endl;



    }


        cout << "Reconnu : " << success << endl
             << "Non reconnu : " << nonReconnu << endl
             << "Erreurs: " << fail << endl
             << "Taux d'erreurs: " << fail*100/(success+fail+nonReconnu) << " %" << endl
             << "Reconnaissance : " << success*100/(success+fail+nonReconnu) << " %" << endl;



}


OCR::~OCR()
{
    //dtor
}
