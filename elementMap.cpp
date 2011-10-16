

#include "elementMap.hpp"
#include "spriteHandler.hpp"
#include "bddInternalHandler.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

elementMap::elementMap()
{
    cout<<"Creation de l'elementMap basique"<<endl;
}

//surement a suppriemr a voir
elementMap::elementMap(string idElement)
{
    cout<<"Creation de l'elementMap "<<idElement<<endl;
    coordX = 0 ;
    coordY = 0 ;

    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

    spriteEltPrim.SetImage(*instSpriteHandler->getImage(idElement));
    spriteEltPrim.SetPosition(coordX, coordY);
    spriteEltPrim.SetScale(2, 2);

}

elementMap::elementMap(string idElement,int coordXIn,int coordYIn)
{
    //cout<<"Creation de l'elementMap "<<idElement<<" coord("<<coordX<<";"<<coordY<<")"<<endl;
    coordX=coordXIn;
    coordY=coordYIn;

    spriteHandler *instSpriteHandler = spriteHandler::getInstance();

    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    vector<string> listeSpri=instBddInternalHandler->getListeSpritesElem(idElement);

    spriteEltPrim.SetImage(*instSpriteHandler->getImage(listeSpri.at(rand()%listeSpri.size())));
    spriteEltPrim.SetPosition(coordX, coordY);
    spriteEltPrim.SetScale(2, 2);

}

elementMap::~elementMap()
{
    cout<<"Desctruction de la map"<<endl;
}


void elementMap::affiche(RenderWindow &fenAffichage)
{
    fenAffichage.Draw(spriteEltPrim);
}

