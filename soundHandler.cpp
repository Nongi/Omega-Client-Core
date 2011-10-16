#include "soundHandler.hpp"
#include "bddInternalHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

soundHandler *soundHandler::singleton = NULL;

//constructeur
soundHandler::soundHandler()
{
    cout<<"Creation du singleton soundHandler"<<endl;
    loadSounds();
}

//destructeur vidant le map des sons
soundHandler::~soundHandler()
{
    //On détruit toutes les sons restantes
    map<string, SoundBuffer*>::iterator itSound;
    for(itSound = stockSounds.begin(); itSound != stockSounds.end(); itSound++)
    {
        delete itSound->second;
    }
}


bool soundHandler::SearchSound(const string &SoundLink, SoundBuffer* &SoundTemp)
{
    map<string, SoundBuffer*>::iterator it;

    it = stockSounds.find(SoundLink);

    if(it == stockSounds.end())
    {
        return false;
    }
    else
    {
        SoundTemp = it->second;
    }

    return true;
}


SoundBuffer *soundHandler::CreateSound(const string &SoundLink)
{
    SoundBuffer *SoundTemp = new SoundBuffer();
    if(SoundTemp->LoadFromFile("Sounds\\"+SoundLink+".wav"))
    {
        stockSounds[SoundLink]=SoundTemp;
        return SoundTemp;
    }
    else
    {
        delete SoundTemp;
    }

    return NULL;
}

void soundHandler::loadSounds()
{
    cout << "Debut de la phase de chargement des sounds\n";

    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    vector<string> listeSounds=instBddInternalHandler->getListeSounds();

    for ( vector<string>::iterator i = listeSounds.begin(); i != listeSounds.end();i++ )
    {
        if(CreateSound(*i))
            cout << *i << " son charger\n";
        else
            cout << *i << " son non charger\n";
    }
    cout << "Fin de la phase de chargement des sounds\n";
}


SoundBuffer *soundHandler::getSound(const string &SoundLink)
{
    SoundBuffer *SoundTemp;

    //Si le son demandée n'existe pas déjà, on la créée
    if(!SearchSound(SoundLink, SoundTemp))
    {
        SoundTemp = CreateSound(SoundLink);
    }

    return SoundTemp;
}


void soundHandler::DeleteSound(SoundBuffer &Son)
{
    map<string, SoundBuffer*>::iterator it;

    //On cherche le son demandée
    for(it = stockSounds.begin(); it != stockSounds.end(); it++)
    {
    //Si on le trouve, on le détruit et on le retire
        if(it->second == &Son)
        {
            delete &Son;
            stockSounds.erase(it);
            break;
        }
    }
}


void soundHandler::DeleteSound(const string& SoundLink)
{
    map<string, SoundBuffer*>::iterator it;

    it = stockSounds.find(SoundLink);

    if(it != stockSounds.end())
    {
        if(it->second != NULL)
        {
            delete (it->second);
            stockSounds.erase(it);
        }
    }
}
