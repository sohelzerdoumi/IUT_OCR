#include <iostream>
#include <iomanip>

#include "MyImage.h"
#include "OCR.h"
#include "utils.h"
#include "extlib/SimpleOpt.h"
#include "extlib/SimpleGlob.h"

using namespace std;

enum { OPT_HELP, OPT_TEST, OPT_ARG, OPT_FILE };

CSimpleOpt::SOption g_rgOptions[] = {
    { OPT_TEST, ("--test"),     SO_NONE    }, // "-a"
    { OPT_TEST, ("-t"),     SO_NONE    }, // "-a"
    { OPT_FILE,  ("-f"),     SO_REQ_SEP }, // "-f ARG"
    { OPT_FILE,  ("--file"),     SO_REQ_SEP }, // "-f ARG"
    { OPT_HELP, ("-?"),     SO_NONE    }, // "-?"
    { OPT_HELP, ("--help"), SO_NONE    }, // "--help"
    SO_END_OF_OPTIONS                       // END
};


void ShowHelp(string filename){
        int option_width = 20;
        int description_dist = 10;
        cout    << " Utilisation :" << endl;

        cout << setw(option_width) << "-t, --test"
             << setw(description_dist) << ""
             << "Genere la matrice de confusion" << endl;


        cout << setw(option_width) << "-f FILE, --file=FILE"
             << setw(description_dist) << ""
              << "Trouve le caractere correspondant à l'image" << endl;
}

int main(int argc, char ** argv)
{
    loadConfigFile();

    CSimpleOpt args(argc, argv, g_rgOptions);

    while (args.Next()) {
        if (args.LastError() == SO_SUCCESS) {
            switch(args.OptionId() ) {
                case OPT_HELP:
                    ShowHelp(argv[0]);
                    return 0;
                    break;

                case OPT_TEST:
                    OCR::instance()->displayConfusionMatrix();
                    return 0;
                    break;
                case OPT_FILE:
                    MyImage img(args.OptionArg() );
                    Correspondance c = OCR::instance()->getCorrespondance(img);
                    cout << "Correspondance : " << endl
                         << " taux = " << 100-c.diffMin << "%"<< endl
                         << " classe = " << c.nomClasse << endl;
                    return 0;
                    break;

            }
        }

    }

    ShowHelp(argv[0]);
    return EXIT_SUCCESS;
}
