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
    initAnimation(idAnim);
}

animation::animation(string idAnim, bool loopIn)
{
    if(loopIn)
        setLoopEnable();
    else
        setLoopDisable();
    initAnimation(idAnim);
}


//création d'animation avec une liste de nom de sprite
animation::animation(std::vector<std::string> listeSpriteIn,float vitIn)
{
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

    setLoopEnable();
    setPosition(50,50);

    spriteBase="scientifiqueFront";
    listeNameSpritesAnim.push_back("scientifiqueFront1");
    listeNameSpritesAnim.push_back("scientifiqueFront2");

    idSpriteCourant=0;
    vitesse=0.30;

    cout<<"Creation de l'animation"<<endl;
}

void animation::initAnimation(string idAnim)
{
    idAnimation=idAnim;
    spriteHandler *instSpriteHandler = spriteHandler::getInstance();
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();

    setLoopEnable();
    setPosition(50,50);
    setScale(2,2);

    idSpriteCourant=0;

    vitesse=instBddInternalHandler->getVitesseAnimation(idAnim);
    map<int,string> listeAnim=instBddInternalHandler->getAnimation(idAnim);
    map<int,string>::iterator it;

    for(it = listeAnim.begin(); it!= listeAnim.end() ; ++it)
    {
        if(it->first==0)
            spriteBase=it->second;
        else
            listeNameSpritesAnim.push_back(it->second);
    }
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

    /*
    //Flag de bonne lecture des srites d'animations avec le timer interne de l'animation
    cout<<"timer :"<<time<<" et frame :"<<idSpriteCourant<<endl;
    */
}
