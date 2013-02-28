#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyImage.h"
#include "OCR.h"

using namespace std;

int main()
{
    MyImage a("base/2/2_1.png");
    MyImage b("base/2/2_3.png");
    //a.Resize(23,21);
    //a.generateHistogrammes();
    cout << a.compare(b) << endl;
//    OCR::instance();
    return EXIT_SUCCESS;
}
