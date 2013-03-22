#include "MyImage.h"
#include "utils.h"
#include "MD5.h"

#include <cmath>
#include <iostream>

using namespace cimg_library;
using namespace std;

MyImage::MyImage(std::string filename,int largeur, int hauteur )
: _cimg(filename.c_str())
{
    _filename = filename;
    toBinary();
    _cimg.autocrop(255);
    _cimg.resize(largeur,hauteur);

    loadCaracteristiques();
}

MyImage::MyImage(const sf::Image & i)
{
    _cimg.resize( i.GetWidth(), i.GetHeight() );
    for(int c = 0; c < (signed)i.GetWidth() ;c++ )
        for(int r = 0; r < (signed)i.GetHeight() ;r++ ){
            _cimg.data(c,r)[0] = i.GetPixel(c,r).r;
            _cimg.data(c,r)[1] = i.GetPixel(c,r).g;
            _cimg.data(c,r)[2] = i.GetPixel(c,r).b;
        }

    toBinary();
    _cimg.autocrop(255);
    _cimg.resize(IMG_HAUTEUR,IMG_LARGEUR);

    loadCaracteristiques();
}

MyImage::MyImage(const std::vector<const MyImage*> & images){
    if( images.size() == 0)
        return;
    vector<const Caracteristique *> caracteristiques;

    for(int idCaracteristique =0; idCaracteristique < (signed)images[0]->_caracteristiques.size() ; idCaracteristique++ ){
        caracteristiques.clear();
        for( auto img : images ){
            caracteristiques.push_back( img->_caracteristiques[idCaracteristique] );
        }
        _caracteristiques.push_back( new Caracteristique( caracteristiques ) ) ;
    }



}

MyImage::MyImage(const MyImage & i, int largeur, int hauteur)
: _cimg(i._filename.c_str())
{
    _filename = i._filename;
    toBinary();
    _cimg.autocrop(255);
    _cimg.resize(largeur,hauteur);
    loadCaracteristiques();
}

MyImage::MyImage(const MyImage & i)
: _cimg( i._filename.c_str())
{
    _filename = i._filename;
    toBinary();
    _cimg.autocrop(255);
    loadCaracteristiques();
}

/**
 * Convertie l'image en binaire
 */
void MyImage::toBinary(){
    int largeur = _cimg.width();
    int hauteur =  _cimg.height();
    int * currentPixel;


    for(int c = 0; c < largeur ; c++ )
        for(int l = 0 ; l < hauteur ; l++){
            currentPixel = _cimg.data(c,l);
            currentPixel[0] = (currentPixel[0] > 200) * 255;
        }

}




float MyImage::compare(const MyImage & img, const std::string & classeName) const{
    float somme_ponderation = 0;
    float diff = 0;
    for(int i=0; i < (signed)_caracteristiques.size() ; i++){
        if( getConfigValueString("ocr.caracteristique.mode") == "defaut" ){
            diff += _caracteristiques[i]->compare(img._caracteristiques[i])*_caracteristiques[i]->ponderation;
            somme_ponderation += _caracteristiques[i]->ponderation;
        }
        if( getConfigValueString("ocr.caracteristique.mode") == "cible" ){
            if( isConfigValuesContainString( "ocr.caracteristique.cible." + _caracteristiques[i]->nom , classeName)){
                diff += _caracteristiques[i]->compare(img._caracteristiques[i])*_caracteristiques[i]->ponderation;
                somme_ponderation += _caracteristiques[i]->ponderation;
            }
        }
    }

    return diff/somme_ponderation;
}

void MyImage::generateCaracteristiques(){
    for( Caracteristique * carac : _caracteristiques)
        carac->generate();

}
void MyImage::loadCaracteristiques(){
    if( getConfigValueString("ocr.caracteristique.mode") == "defaut" ){
        if( getConfigValueBoolean("ocr.caracteristique.defaut.courbure.enable")  )
            _caracteristiques.push_back( new  Courbure(&_cimg));
        if( getConfigValueBoolean("ocr.caracteristique.defaut.profil.enable")  )
            _caracteristiques.push_back( new  Profil(&_cimg));
        if( getConfigValueBoolean("ocr.caracteristique.defaut.isoperimetre.enable")   )
            _caracteristiques.push_back( new  Isoperimetre(&_cimg));
        if( getConfigValueBoolean("ocr.caracteristique.defaut.zoning.enable")   )
            _caracteristiques.push_back( new  Zoning(&_cimg));
        if( getConfigValueBoolean("ocr.caracteristique.defaut.momentgeometrique.enable") )
            _caracteristiques.push_back( new  MomentGeometrique(&_cimg));
    }else{
        _caracteristiques.push_back( new  Courbure(&_cimg));
        _caracteristiques.push_back( new  Profil(&_cimg));
        _caracteristiques.push_back( new  Isoperimetre(&_cimg));
        _caracteristiques.push_back( new  Zoning(&_cimg));
        _caracteristiques.push_back( new  MomentGeometrique(&_cimg));
    }

    generateCaracteristiques();
}


std::string                 MyImage::getMD5() const{
    int largeur = _cimg.width();
    int hauteur =  _cimg.height();
    string datas;
    for(int c = 0; c < largeur ; c++ )
        for(int l = 0 ; l < hauteur ; l++){
            datas += intToString(_cimg.data(c,l)[0]);
        }
    return md5(datas);
}

void MyImage::display() const{
    _cimg.display();

}

bool MyImage::operator==(const MyImage & i) const{
    return _filename == i._filename;
}


MyImage::~MyImage(){
    for( Caracteristique * carac : _caracteristiques)
        delete carac;

}
