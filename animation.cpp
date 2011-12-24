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
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

    setLoopEnable();
    setPosition(50,50);

    //listeNameSpritesAnim.push_back("scientifiqueFront");
    listeNameSpritesAnim.push_back("scientifiqueFront1");
    listeNameSpritesAnim.push_back("scientifiqueFront2");

    //listeNameSpritesAnim.push_back(spriteTemp.SetImage(*instSpriteHandler->getImage("scientifiqueFront2")));
    //listeNameSpritesAnim.push_back(spriteTemp.SetImage(*instSpriteHandler->getImage("scientifiqueFront3")));

    idSpriteCourant=0;
    vitesse=0.30;

    cout<<"Creation de l'animation "+idAnim<<endl;
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

float animation::getTimer()
{
    return timerC.GetElapsedTime();
}

void animation::afficher(RenderWindow &fenAffichage)
{
    updateSprite();
    fenAffichage.Draw(spriteCourant);
}

void animation::updateSprite(){
    updateSpriteNumber();

    spriteHandler *instSpriteHandler = spriteHandler::getInstance();
    spriteCourant.SetImage(*instSpriteHandler->getImage(listeNameSpritesAnim[idSpriteCourant]));
    spriteCourant.SetPosition(coordX,coordY);
    spriteCourant.SetScale(2, 2);
}

void animation::updateSpriteNumber(){
    float time=timerC.GetElapsedTime();

    if(time<vitesse*listeNameSpritesAnim.size())
    {
        idSpriteCourant=(time/vitesse);
    }
    else{
        timerC.Reset();
    }

    cout<<"timer :"<<time<<" et frame :"<<idSpriteCourant<<endl;
}
