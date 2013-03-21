#include "Fenetre.h"
#include "OCR.h"
#include <iostream>

#define WINDOW_WIDTH   200
#define WINDOW_HEIGHT  150

using namespace std;

Fenetre::Fenetre()
: _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Projet OCR" )
{
    _window.Show(true);
}

void Fenetre::run(){
    sf::Event event;
    clearWindow();
    while(_window.IsOpened()){
        sf::Sleep(1.0f/100);
        while( _window.GetEvent(event) )
               treatEvent(event);



    }

}

void Fenetre::treatEvent( sf::Event & event){
    if (event.Type == sf::Event::Closed)
                _window.Close();
    int mouseX = _window.GetInput().GetMouseX(); // event.MouseButton.X;
    int mouseY = _window.GetInput().GetMouseY(); //event.MouseButton.Y;


    if( ( event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::C)  ){
        MyImage img( _window.Capture() );
        Correspondance c = OCR::instance()->getCorrespondance(img);
        cout << "Correspondance : " << endl
             << " taux = " << 100-c.diffMin << "%"<< endl
             << " classe = " << c.nomClasse << endl;
    }


    if( mouseX < 0 or mouseX > WINDOW_WIDTH or mouseY < 0 or mouseY > WINDOW_HEIGHT )
        return;

    if( _window.GetInput().IsMouseButtonDown(sf::Mouse::Left))
    {
        sf::Shape pinceau = sf::Shape::Rectangle(mouseX-3, mouseY-3, mouseX+3, mouseY+3, sf::Color::Black);
        _window.Draw(pinceau);
        _window.Display();

    }

    if( _window.GetInput().IsMouseButtonDown(sf::Mouse::Right))
    {
       _window.Clear(sf::Color::White);
        _window.Display();

    }

}

void Fenetre::clearWindow(){
    _window.Clear(sf::Color::White);
    _window.Display();
}

Fenetre::~Fenetre()
{
    //dtor
}
