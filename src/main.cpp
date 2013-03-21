#include <iostream>
#include <iomanip>
#include "Fenetre.h"

#include "MyImage.h"
#include "OCR.h"
#include "utils.h"
#include "SimpleOpt.h"
#include "SimpleGlob.h"

using namespace std;

enum OPT_T{ OPT_FLAG, OPT_CONFIG_FILE,  OPT_ACTION, ACT_TEST, ACT_CORRESPONDANCE, ACT_HELP, ACT_GUI  };

CSimpleOpt::SOption g_rgOptions[] = {
    { OPT_CONFIG_FILE ,     ("-c"),         SO_REQ_SEP },
    { OPT_CONFIG_FILE ,     ("--config"),   SO_REQ_SEP },

    { OPT_FLAG ,            ("--display"),   SO_NONE },



    { ACT_GUI ,            ("-X"),         SO_NONE    },
    { ACT_TEST ,            ("-t"),         SO_NONE    },
    { ACT_TEST ,            ("--test"),     SO_NONE    },
    { ACT_CORRESPONDANCE ,  ("-f"),         SO_REQ_SEP },
    { ACT_CORRESPONDANCE ,  ("--file"),     SO_REQ_SEP },
    { ACT_HELP ,            ("-r"),         SO_MULTI    },
    { ACT_HELP ,            ("-h"),         SO_NONE    },
    { ACT_HELP ,            ("--help"),     SO_NONE    },
    SO_END_OF_OPTIONS
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



void runTests(){
    OCR::instance()->displayConfusionMatrix();
}

void runCorrespondance(const string & option, const map<string,string> & flags){
        MyImage img( option );
        Correspondance c = OCR::instance()->getCorrespondance(img);
        cout << "Correspondance : " << endl
             << " taux = " << 100-c.diffMin << "%"<< endl
             << " classe = " << c.nomClasse << endl;

        if( flags.find("--display") != flags.end()  )
            img.display();
}

void runGUI(const string & option, const map<string,string> & flags){
    OCR::instance();
    Fenetre f;
    f.run();
}

int main(int argc, char ** argv)
{


    OPT_T action = ACT_HELP;
    string action_option ;
    std::map<std::string, std::string> flags;

    loadConfigFile();

    CSimpleOpt args(argc, argv, g_rgOptions);

    /*
     * Analyse des parametres
     */
    while (args.Next()) {
        if (args.LastError() == SO_SUCCESS) {
            switch(args.OptionId() ) {
                case ACT_TEST:
                    action = ACT_TEST ;
                    break;
                case ACT_GUI:
                    action = ACT_GUI ;
                    break;
                case ACT_CORRESPONDANCE:
                    action = ACT_CORRESPONDANCE ;
                    action_option = args.OptionArg();
                    break;
                case ACT_HELP:

                    cout << args.MultiArg(20) << endl;
                    action = ACT_HELP;
                    break;

                case OPT_CONFIG_FILE:
                    loadConfigFile(args.OptionArg());
                    break;

                case OPT_FLAG:
                    flags[ args.OptionText() ] = ""; //args.OptionArg();
                    break;
            }
        }

    }

    /*
     * Choix de l'action
     */
    switch( action ) {
                case ACT_TEST:
                    runTests();
                    break;

                case ACT_CORRESPONDANCE:
                    runCorrespondance( action_option, flags);
                    break;

               case ACT_GUI:
                    runGUI( action_option, flags);
                    break;


                case ACT_HELP:
                default:
                    ShowHelp(argv[0]);
                    break;

    }


    return EXIT_SUCCESS;
}
