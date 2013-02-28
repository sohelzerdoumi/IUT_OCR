#include "Histogramme.h"

#include <stdlib.h>

Histogramme::Histogramme()
{
    data = NULL;
}

Histogramme::~Histogramme()
{
   if( data != NULL)
    delete data;
}
