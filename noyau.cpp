
#include "noyau.hpp"
#include "spriteHandler.hpp"
#include "soundHandler.hpp"
#include "musicHandler.hpp"
#include "bddInternalHandler.hpp"
#include "mapHandler.hpp"
#include "animation.hpp"


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

using namespace sf;
using namespace std;


// initialisation du pointeur de singleton à zéro
// (insérer dans le .cpp)
noyau *noyau::singleton = NULL;

RenderWindow fenetrePrincipal;

noyau::noyau()
{
    std::cout<<"Eveil du Noyau"<<std::endl;
    fenetrePrincipal.Create(VideoMode(800, 600, 32), "Omega 0.1");
}

void noyau::run()
{
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();
    soundHandler *instSoundHandler = soundHandler::getInstance();
    musicHandler *instMusicHandler = musicHandler::getInstance();

    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();

    mapHandler *instMapHandler = mapHandler::getInstance();

    instMusicHandler->getMusic("SkinnyLove")->Play();

    Sprite spriteIn;
    spriteIn.SetImage(*instSpriteHandler->getImage("scientifiqueFront"));
    spriteIn.SetPosition(200, 100);
    spriteIn.SetScale(2, 2);

    Sound soundActivate;
    soundActivate.SetBuffer(*instSoundHandler->getSound("activated"));
    soundActivate.Play();

    animation firstAnim = animation("coucou");
    //firstAnim.afficher(fenetrePrincipal);

    // Start game loop
    while (fenetrePrincipal.IsOpened())
    {
        // Process events
        Event Event;
        while (fenetrePrincipal.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == Event::Closed || fenetrePrincipal.GetInput().IsKeyDown(Key::Escape))
                fenetrePrincipal.Close();
        }

        // Get elapsed time
        float ElapsedTime = fenetrePrincipal.GetFrameTime();

        if (Event.Key.Code == Key::F12)
        {
            fenetrePrincipal.Capture().SaveToFile("Screenshot\\screenshot1.jpg");
            cout<<"screen effectué"<<endl;
        }

        // Move the sprite

        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Left))  spriteIn.Move(-100 * ElapsedTime, 0);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Right)) spriteIn.Move( 100 * ElapsedTime, 0);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Up))    spriteIn.Move(0, -100 * ElapsedTime);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Down))  spriteIn.Move(0,  100 * ElapsedTime);

        // Rotate the sprite
        //if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Add))      Sprite.Rotate(- 100 * ElapsedTime);

        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::R)) spriteIn.Rotate(+ 100 * ElapsedTime);

        // Clear screen
        fenetrePrincipal.Clear();

        // Display sprite in our window
        instMapHandler->afficherAll(fenetrePrincipal);
        fenetrePrincipal.Draw(spriteIn);

        // Display window contents on screen
        fenetrePrincipal.Display();
    }
}



