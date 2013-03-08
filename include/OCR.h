#ifndef OCR_H
#define OCR_H
#define PATH_BASE "base"

#include <stdlib.h>
#include <vector>

#include "Classe.h"

struct Correspondance{
    float diffMin;
    Classe * classe;

} ;

class OCR
{
    public:
        static OCR *        instance();
        static void         destroy();
        Correspondance      getCorrespondance(MyImage & image) const;
        void                displayConfusionMatrix() const;

    private:
        OCR();
        virtual ~OCR();
        std::vector<Classe *>   _classes;
        static OCR *            _instance;


};

#endif // OCR_H
