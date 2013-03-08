#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyImage.h"
#include "OCR.h"

using namespace std;

int main(int argc, char ** argv)
{
    #ifndef DEBUG_MODE
    if( argc < 2){
        cout    << " Usage :" << endl
                << argv[0] << " (filename) " << endl;
        return EXIT_SUCCESS;
    }
    MyImage a(argv[1]);
    #else
    MyImage a("tests/9.png");

    #endif


   Correspondance c = OCR::instance()->getCorrespondance(a);
    cout << "Correspondance : " << endl
         << " taux = " << 100-c.diffMin << "%"<< endl
         << " classe = " << c.classe->nom << endl;

    //a.display();


    OCR::instance()->displayConfusionMatrix();

    a.display();
    //a._cimg.dilate(1).display();


    return EXIT_SUCCESS;
}
