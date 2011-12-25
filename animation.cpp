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
    setScale(2,2);

    spriteBase="scientifiqueFront";
    listeNameSpritesAnim.push_back("scientifiqueFront1");
    listeNameSpritesAnim.push_back("scientifiqueFront2");

    //listeNameSpritesAnim.push_back(spriteTemp.SetImage(*instSpriteHandler->getImage("scientifiqueFront2")));

    idSpriteCourant=0;
    vitesse=0.30;

    cout<<"Creation de l'animation "+idAnim<<endl;
}


//création d'animation avec une liste de sprite
animation::animation(std::vector<std::string> listeSpriteIn,float vitIn)
{
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

    setLoopEnable();
    setPosition(50,50);

    spriteBase="scientifiqueFront";
    listeNameSpritesAnim.push_back("scientifiqueFront1");
    listeNameSpritesAnim.push_back("scientifiqueFront2");

    //listeNameSpritesAnim.push_back(spriteTemp.SetImage(*instSpriteHandler->getImage("scientifiqueFront2")));

    idSpriteCourant=0;
    vitesse=0.30;

    cout<<"Creation de l'animation"<<endl;
}

void animation::move(int coordXIn,int coordYIn)
{
    spriteCourant.Move(coordXIn,coordYIn);
}

void animation::setPosition(int coordXIn,int coordYIn)
{

    spriteCourant.SetPosition(coordXIn,coordYIn);
}

void animation::setScale(float xIn, float yIn){
    spriteCourant.SetScale(xIn,yIn);
}

void animation::play()
{
    run=true;
}

void animation::stop()
{
    run=false;
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

//fonction d'affichage comme un sprite normal
void animation::afficher(RenderWindow &fenAffichage)
{
    updateSprite();
    fenAffichage.Draw(spriteCourant);
}

//va changer le sprite courant si besoin en fonction du temps écoulé
void animation::updateSprite(){
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();
    if(run){
        updateSpriteNumber();
        spriteCourant.SetImage(*instSpriteHandler->getImage(listeNameSpritesAnim[idSpriteCourant]));
    }
    else
        spriteCourant.SetImage(*instSpriteHandler->getImage(spriteBase));
}


//en fonction du temps qui est passé identifie le sprite à afficher en utilisant la vitesse et le nombre d'image remet a zéro le compteur si loop est active
void animation::updateSpriteNumber(){
    float time=timerC.GetElapsedTime();

    if(time<vitesse*listeNameSpritesAnim.size())
    {
        idSpriteCourant=(time/vitesse);
    }
    else{
        if(loop)
            timerC.Reset();
    }

    cout<<"timer :"<<time<<" et frame :"<<idSpriteCourant<<endl;
}
