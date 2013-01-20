#include "musicHandler.hpp"
#include "bddInternalHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

musicHandler *musicHandler::singleton = NULL;

//constructeur
musicHandler::musicHandler()
{
    cout<<"Creation du singleton musicHandler"<<endl;
    loadMusics();
}

//destructeur vidant le map des sons
musicHandler::~musicHandler()
{
    //On détruit toutes les musiques restantes
    map<string, Music*>::iterator itMusique;
    for(itMusique = stockMusics.begin(); itMusique != stockMusics.end(); itMusique++)
    {
        delete itMusique->second;
    }
}



bool musicHandler::SearchMusic(const string &MusicLink, Music* &MusicTemp)
{
    map<string, Music*>::iterator it;

    it = stockMusics.find(MusicLink);

    if(it == stockMusics.end())
    {
        return false;
    }
    else
    {
        MusicTemp = it->second;
    }

    return true;
}


Music *musicHandler::CreateMusic(const string &MusicLink)
{
    Music *MusicTemp = new Music();
    if(MusicTemp->OpenFromFile("Musics\\"+MusicLink+".ogg"))
    {
        stockMusics[MusicLink]=MusicTemp;
        return MusicTemp;
    }
    else
    {
        delete MusicTemp;
    }

    return NULL;
}

void musicHandler::loadMusics()
{
    cout << "Debut de la phase de chargement des musiques\n";

    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    vector<string> listeMusics=instBddInternalHandler->getListeMusics();

    for ( vector<string>::iterator i = listeMusics.begin(); i != listeMusics.end();i++ )
    {
        if(CreateMusic(*i))
            cout << *i << " musique charger\n";
        else
            cout << *i << " musique non charger\n";
    }

    cout << "Fin de la phase de chargement des musiques\n";
}


Music *musicHandler::getMusic(const string &MusicLink)
{
    Music *MusicTemp;

    //Si le morceau de musique demandée n'existe pas déjà, on le créée
    if(!SearchMusic(MusicLink, MusicTemp))
    {
        MusicTemp = CreateMusic(MusicLink);
    }

    return MusicTemp;
}


void musicHandler::DeleteMusic(Music &Musique)
{
    map<string, Music*>::iterator it;

    //On cherche lle morceau de musique demandée
    for(it = stockMusics.begin(); it != stockMusics.end(); it++)
    {
    //Si on le trouve, on le détruit et on le retire
        if(it->second == &Musique)
        {
            delete &Musique;
            stockMusics.erase(it);
            break;
        }
    }
}


void musicHandler::DeleteMusic(const string& MusicLink)
{
    map<string, Music*>::iterator it;

    it = stockMusics.find(MusicLink);

    if(it != stockMusics.end())
    {
        if(it->second != NULL)
        {
            delete (it->second);
            stockMusics.erase(it);
        }
    }
}
