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
    for(std::string &dir : dirs )
            _classes.push_back( new Classe( dir) );

    

}

/**
 * Analyse une image afin de determiner sa forme
 * @param image : image  à analyser
 * @return Correspondance : structure contenant le rapport
 */
Correspondance OCR::getCorrespondance(const MyImage & image) const{
    Correspondance c={0,""};
    float differenceMin = 100000000;
    float tmp_diff = 10000000;
    const Classe *  classe_diffMin = 0;
    for(const Classe * classeCurrent : _classes ){
        tmp_diff = classeCurrent->getCorrespondance(image);

        if( tmp_diff < differenceMin  ){
            differenceMin = tmp_diff;
            classe_diffMin = classeCurrent;
        }
    }
    if( classe_diffMin != 0){
        c.diffMin = differenceMin;
        c.nomClasse  =  (differenceMin < getConfigValueInt("ocr.difference_max") ) ? classe_diffMin->nom : "?";
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
     cout << "    |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  ?" << endl;
     cout << std::setfill('-') << std::setw(62)  << " " << std::setfill(' ')  << endl ;

    /*
     *  Rapport par classe
     */
    for(const Classe * classeCurrent : _classes){

        rapport = classeCurrent->test();
        cout << "   " << classeCurrent->nom ;
        for(int j=0; j < 10 ; j++){
             if( rapport.find( std::to_string(j)) ==rapport.end() ){
                cout << "|  0 " ;
             }else{
                cout << "| " ;

                if( classeCurrent->nom == std::to_string(j) ){
                    success += rapport[std::to_string(j)];
                    cout << IO_BOLDGREEN << IO_BG_GREY;  // Vert
                }
                else{
                    fail += rapport[std::to_string(j)] ;
                    cout << IO_BOLDYELLOW << IO_BG_RED;  // Rouge
                }

                cout <<  setw(2) << rapport[std::to_string(j)] << " ";
                cout << IO_RESET   ;
             }
        }

        nonReconnu += rapport["?"] ;
        cout << "| " << IO_BOLDGREEN << IO_BG_BLUE <<setw(2) << rapport["?"] << " " << IO_RESET ;




        cout << endl;



    }


        cout << "Reconnu : " << success << endl
             << "Non reconnu : " << nonReconnu << endl
             << "Erreurs: " << fail << endl
             << "Taux d'erreurs: " << setw(5) << fail*100.0f/(success+fail+nonReconnu) << " %" << endl
             << "Reconnaissance : " << setw(5) << success*100.0f/(success+fail+nonReconnu) << " %" << endl;



}


OCR::~OCR()
{
    //dtor
}
