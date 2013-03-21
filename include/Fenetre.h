#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>

class Fenetre
{
    public:
        /** Default constructor */
        Fenetre();
        virtual ~Fenetre();

        void run();
        void treatEvent(sf::Event & event);
        void clearWindow();

    private:
        sf::RenderWindow _window;

};

#endif // FENETRE_H
