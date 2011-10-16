#include "animation.hpp"
#include "spriteHandler.hpp"
#include "bddInternalHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

using namespace sf;
using namespace std;

animation::animation()
{
    setLoopEnable();
}

animation::animation(string idAnim)
{

    setLoopEnable();

    setPosition(50,50);
    vector<string> listeNameSpritesAnim;

    listeNameSpritesAnim.push_back("scientifiqueFront");
    listeNameSpritesAnim.push_back("scientifiqueFront1");
    listeNameSpritesAnim.push_back("scientifiqueFront2");

    spriteCourant=0;

    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

   /* for (vector<string> listeNameSpritesAnim: myString)
    {
        Sprite spriteAnim;
        spriteAnim.SetImage(*instSpriteHandler->getImage(myString));
        spriteAnim.SetPosition(coordX, coordY);
        spriteAnim.SetScale(2, 2);
    }*/

    cout<<"Création de l'animation "+idAnim<<endl;
}

void animation::setModificationPos(int coordXIn,int coordYIn)
{
    coordX+=coordXIn;
    coordY+=coordYIn;
}

void animation::setPosition(int coordXIn,int coordYIn)
{
    coordX=coordXIn;
    coordY=coordYIn;
}

void animation::play()
{

}

void animation::play(int coordXIn, int coordYIn)
{

}

void animation::play(int timeIn)
{

}

void animation::play(int coordXIn, int coordYIn, int timeIn)
{

}

void animation::pause()
{

}

void animation::stop()
{

}

void animation::setLoopEnable()
{
    loop=true;
}

void animation::setLoopDisable()
{
    loop=false;
}

int animation::getTimer()
{
    return timer;
}

void animation::afficher(RenderWindow &fenAffichage)
{
    fenAffichage.Draw(listeSpritesAnim.at(spriteCourant));
}
