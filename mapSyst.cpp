
#include "mapSyst.hpp"
#include "bddInternalHandler.hpp"

#include <vector>
#include <iostream>

mapSyst::mapSyst()
{
    cout<<"Creation de la map"<<endl;
}

mapSyst::mapSyst(string idMap)
{
    cout<<"Creation de la map"<<endl;
    initPrimaire(idMap);
}

mapSyst::mapSyst(int idMap)
{
    cout<<"Creation de la map"<<endl;
    initPrimaire(idMap);
}

mapSyst::~mapSyst()
{
    cout<<"Desctruction de la map"<<endl;
}

void mapSyst::initPrimaire(string idMap)
{
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();

    largeur = instBddInternalHandler->getMapLargeur(idMap);
    longueur = instBddInternalHandler->getMapLongueur(idMap);

    vector<string> mapIn=instBddInternalHandler->getMapPrimaire(idMap);

    int counterLargeur=0,counterLongueur=0;

    for(int i=0;i<mapIn.size();i++)
    {
        for(int j=0;j<atoi(mapIn.at(i).c_str());j++)

                if(counterLargeur==largeur-1)
                {
                    elementMap* elemTemp= new elementMap(mapIn.at(i+1),32*counterLargeur,32*counterLongueur);
                    couchePrimaire.push_back(elemTemp);
                    counterLargeur=0;
                    counterLongueur++;
                }
                else
                {
                    elementMap* elemTemp= new elementMap(mapIn.at(i+1),32*counterLargeur,32*counterLongueur);
                    couchePrimaire.push_back(elemTemp);
                    counterLargeur++;
                }
        i++;
    }
}

void mapSyst::initPrimaire(int idMap)
{
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();

    largeur = instBddInternalHandler->getMapLargeur(idMap);
    longueur = instBddInternalHandler->getMapLongueur(idMap);

    vector<string> mapIn=instBddInternalHandler->getMapPrimaire(idMap);

    int counterLargeur=0,counterLongueur=0;

    for(int i=0;i<mapIn.size();i++)
    {
        for(int j=0;j<atoi(mapIn.at(i).c_str());j++)

                if(counterLargeur==largeur-1)
                {
                    elementMap* elemTemp= new elementMap(mapIn.at(i+1),32*counterLargeur,32*counterLongueur);
                    couchePrimaire.push_back(elemTemp);
                    counterLargeur=0;
                    counterLongueur++;
                }
                else
                {
                    elementMap* test= new elementMap(mapIn.at(i+1),32*counterLargeur,32*counterLongueur);
                    couchePrimaire.push_back(test);
                    counterLargeur++;
                }
        i++;
    }
}

void mapSyst::afficherAll(RenderWindow &fenAffichage)
{
    for(int j=0;j<longueur*largeur;j++)
    {
        couchePrimaire.at(j)->affiche(fenAffichage);
    }
}

int mapSyst::getLargeur()
{
    return largeur;
}

int mapSyst::getLongueur()
{
    return longueur;
}
