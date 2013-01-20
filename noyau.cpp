
#include "noyau.hpp"
#include "spriteHandler.hpp"
#include "soundHandler.hpp"
#include "musicHandler.hpp"
#include "bddInternalHandler.hpp"
#include "mapHandler.hpp"
#include "animation.hpp"
#include "board.hpp"


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
    cout<<"Eveil du Noyau"<<endl;
    fenetrePrincipal.Create(VideoMode(800, 600, 32), "Omega 0.1");
}

void noyau::run()
{
    //------------------------------------------------------------------------------------------------------

    // Ensemble des gestionnaires de sprites/sons/musiques
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();
    soundHandler *instSoundHandler = soundHandler::getInstance();
    musicHandler *instMusicHandler = musicHandler::getInstance();

    //Instanciation du gestionnaire de la BDD interne
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();

    //Gestionnaire des maps
    mapHandler *instMapHandler = mapHandler::getInstance();

    //------------------------------------------------------------------------------------------------------


    //Test de musique
    //instMusicHandler->getMusic("SkinnyLove")->Play();

    //Test de son
    Sound soundActivate;
    soundActivate.SetBuffer(*instSoundHandler->getSound("activated"));
    soundActivate.Play();


    //------------------------------------------------------------------------------------------------------


    /*
    //Test d'affichage d'un sprite
    Sprite spriteIn;
    spriteIn.SetImage(*instSpriteHandler->getImage("scientifiqueFront"));
    spriteIn.SetPosition(200, 100);
    spriteIn.SetScale(2, 2);
    */

    animation firstAnim = animation("1");
    //firstAnim.play();
    firstAnim.stop();

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

        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Left))
            firstAnim.move(-100 * ElapsedTime, 0);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Right))
            firstAnim.move( 100 * ElapsedTime, 0);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Up))
            firstAnim.move(0, -100 * ElapsedTime);
        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Down))
        {
            firstAnim.move(0,  100 * ElapsedTime);
            firstAnim.play();
        }



        // Rotate the sprite
        //if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::Add))      Sprite.Rotate(- 100 * ElapsedTime);

        /*if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::R))
            firstAnim.Rotate(+ 100 * ElapsedTime);*/

        if (fenetrePrincipal.GetInput().IsKeyDown(sf::Key::T))
            cout<<"Phase : "<<timerC.GetElapsedTime()<<endl;


        // Clear screen
        fenetrePrincipal.Clear();

        // Display sprite of the map in our window
        instMapHandler->afficherAll(fenetrePrincipal);

        //few test on the Animation classe
        firstAnim.afficher(fenetrePrincipal);
        board titi =  board();
        titi.init(300,300,330,330,sf::Color(255,255,255),"coucou",30,sf::Color(0,0,0),3,sf::Color(0,0,0));
        titi.affiche(fenetrePrincipal);


        /*
        if(timerC.GetElapsedTime()>=10)
        {
            if(timerC.GetElapsedTime()<=20)
                firstAnim.stop();
            else
                firstAnim.play();
        }
        */

        /*

        */

        /*
        sf::Shape Line = sf::Shape::Line(30,30,60,60,3,sf::Color(255,255,255));
        sf::Shape Circle = sf::Shape::Circle(90,90,20,sf::Color(255,255,255),1,sf::Color(0,0,0));
        sf::Shape Rect = sf::Shape::Rectangle(200,200,220,220,sf::Color(255,255,255));
        fenetrePrincipal.Draw(Line);
        fenetrePrincipal.Draw(Circle);
        fenetrePrincipal.Draw(Rect);
        */


        //fenetrePrincipal.Draw(spriteIn);

        // Display window contents on screen
        fenetrePrincipal.Display();
        //fenetrePrincipal.SetView(View);

        firstAnim.stop();
    }
}

float noyau::getTimerNoyau(){
    float time = timerC.GetElapsedTime();
    return time;
}

