#include <utils.h>
#include <iostream>

#include "Classe.h"
#include "OCR.h"

using namespace std;

Classe::Classe(const std::string & nomClasse)
: nom ( nomClasse), _image_mean( NULL )
{
    pathDir = PATH_BASE;
    pathDir += "/";
    pathDir += nom  ;

    std::vector <std::string> dirs =  read_directory( pathDir);
    for(int i = 0; i < (signed)dirs.size() ;i++)
            addImage( dirs[i]);
    _image_mean = new MyImage( _images );

}

Classe::~Classe(){
    if( _image_mean != NULL)
        delete _image_mean ;
}

float  Classe::getCorrespondance(const MyImage & image) const{
    string mode = getConfigValueString("ocr.classe.mode");
    if( mode == "normal")
        return getCorrespondanceNormal(image);

    if( mode == "moyenne")
        return getCorrespondanceMean(image);

    return 0;
}

float Classe::getCorrespondanceNormal(const MyImage & image) const{
    float correspondance = 10000000;
    float tmp_corresp = 10000000;
    for(int i=0; i < (signed)_images.size() ;i++){
        if( !(image == *_images[i]) )
        {
            tmp_corresp = _images[i]->compare(image);
            correspondance = ( tmp_corresp < correspondance ) ? tmp_corresp : correspondance;
        }

    }

    return correspondance;
}

float Classe::getCorrespondanceMean(const MyImage & image) const{
    return _image_mean->compare(image);
}

void Classe::addImage(const std::string & filename){
    const MyImage * image = new MyImage( pathDir + "/" + filename );
    _images.push_back( image);

}

map<string,int>   Classe::test() const{
    map<string,int> rapport;
    string nomClasse;
    for(int i=0; i <  (signed)_images.size() ;i++){
        nomClasse = OCR::instance()->getCorrespondance( *_images[i]).nomClasse;
        if( rapport.find(nomClasse) != rapport.end())
            rapport[nomClasse]++;
        else
            rapport[nomClasse]=1;
    }

    return rapport;
}
