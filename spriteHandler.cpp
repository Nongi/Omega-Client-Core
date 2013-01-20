#include "spriteHandler.hpp"
#include "bddInternalHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

spriteHandler *spriteHandler::singleton = NULL;

//constructeur
spriteHandler::spriteHandler()
{
    cout<<"Creation du singleton spriteHandler"<<endl;
    loadSpritesWName();
}

//destructeur vidant le map
spriteHandler::~spriteHandler()
{
    //On détruit toutes les images restantes
    map<string, Image*>::iterator it;
    for(it = stockImagesWName.begin(); it != stockImagesWName.end(); it++)
    {
        delete it->second;
    }
}

//pas de moi je la comprend fichtre pas et je la supprimerais bien mais sans sa marche pas tip top
bool spriteHandler::SearchImage(const int &ImageLink, Image* &ImgTemp)
{
    map<int, Image*>::iterator it;

    it = stockImages.find(ImageLink);

    if(it == stockImages.end())
    {
        return false;
    }
    else
    {
        ImgTemp = it->second;
    }

    return true;
}

//pas de moi je la comprend fichtre pas et je la supprimerais bien mais sans sa marche pas tip top
bool spriteHandler::SearchImageWName(const string &ImageLink, Image* &ImgTemp)
{
    map<string, Image*>::iterator it;

    it = stockImagesWName.find(ImageLink);

    if(it == stockImagesWName.end())
    {
        return false;
    }
    else
    {
        ImgTemp = it->second;
    }

    return true;
}

//Prévois la création d'une nouvelle image et son stoquage on utilise l'identifiant du sprite comme réferencement et compose son url de chargement
Image *spriteHandler::CreateImage(const int &ImageLink)
{

    //on prépare l'image a stocker dans le map "stockImages"
    Image *ImgTemp = new Image();
    //on essait de crée la sf::Image en utilisant le lien fourni en paramètre en sachant que le dossier des sprites est "Sprites"
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    string ImageName = instBddInternalHandler->getSpriteName(ImageLink);
    //String ImageName = "herbe1";
    if(ImgTemp->LoadFromFile("Sprites\\"+ImageName+".png"))
    {
        //Si la creation à réussi on pense à supprimer l'affichage d'un cadre noir qui pourri tout
        ImgTemp->SetSmooth(false);
        //On peut maintenant stoquer l'image dans le map en utilisant comme identifiant le nom du sprite
        stockImages[ImageLink]=ImgTemp;
        //on renvoie l'image uniquement en cas de réussite
        return ImgTemp;
    }
    else
    {
        //si le chargement à échoué on doit supprimer l'image temporaire
        delete ImgTemp;
    }
    return NULL;
}

//Prévois la création d'une nouvelle image et son stoquage on utilise le nom du sprite comme réferencement et compose son url de chargement
Image *spriteHandler::CreateImageWName(const string &ImageLink)
{
    //on prépare l'image a stocker dans le map "stockImagesW"
    Image *ImgTemp = new Image();
    //on essait de crée la sf::Image en utilisant le lien fourni en paramètre en sachant que le dossier des sprites est "Sprites"
    if(ImgTemp->LoadFromFile("Sprites\\"+ImageLink+".png"))
    {
        //Si la creation à réussi on pense à supprimer l'affichage d'un cadre noir qui pourri tout
        ImgTemp->SetSmooth(false);
        //On peut maintenant stoquer l'image dans le map en utilisant comme identifiant le nom du sprite
        stockImagesWName[ImageLink]=ImgTemp;
        //on renvoie l'image uniquement en cas de réussite
        return ImgTemp;
    }
    else
    {
        //si le chargement à échoué on doit supprimer l'image temporaire
        delete ImgTemp;
    }

    return NULL;
}

//charge une bonne fois pour toute tout les sprites prévu dans la base de donné
void spriteHandler::loadSprites()
{
    cout << "Debut de la phase de chargement des sprites\n";

    //On appel le singleton gestionnaire de la base de donné interne
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    //on lui demande la liste de tous les sprites que l'on stoque dans un vecteur de string listeSprites
    vector<int> listeSprites=instBddInternalHandler->getListeSprites();

    //on parcours le vecteur pour crée toute les sf::Image dans la liste
    for ( vector<int>::iterator i = listeSprites.begin(); i != listeSprites.end();i++ )
    {
        //on tente de les crée et on en informe l'utilisateur du résultat
        if(CreateImage(*i))
            cout << *i << " image charger\n";
        else
            cout << *i << " image non charger\n";
    }
    cout << "Fin de la phase de chargement des sprites\n";
}

//charge une bonne fois pour toute tout les sprites prévu dans la base de donné
void spriteHandler::loadSpritesWName()
{
    cout << "Debut de la phase de chargement des sprites\n";

    //On appel le singleton gestionnaire de la base de donné interne
    bddInternalHandler *instBddInternalHandler = bddInternalHandler::getInstance();
    //on lui demande la liste de tous les sprites que l'on stoque dans un vecteur de string listeSprites
    vector<string> listeSpritesName=instBddInternalHandler->getListeSpritesName();

    //on parcours le vecteur pour crée toute les sf::Image dans la liste
    for ( vector<string>::iterator i = listeSpritesName.begin(); i != listeSpritesName.end();i++ )
    {
        //on tente de les crée et on en informe l'utilisateur du résultat
        if(CreateImageWName(*i))
            cout << *i << " image charger\n";
        else
            cout << *i << " image non charger\n";
    }
    cout << "Fin de la phase de chargement des sprites\n";
}





Image *spriteHandler::getImage(const string &ImageLink)
{
    Image *ImgTemp;

    //Si l'image demandée n'existe pas déjà, on la créée
    if(!SearchImageWName(ImageLink, ImgTemp))
    {
        ImgTemp = CreateImageWName(ImageLink);
    }

    return ImgTemp;
}


Image *spriteHandler::getImage(const int &ImageLink)
{
    Image *ImgTemp;

    //Si l'image demandée n'existe pas déjà, on la créée
    if(!SearchImage(ImageLink, ImgTemp))
    {
        ImgTemp = CreateImage(ImageLink);
    }

    return ImgTemp;
}

void spriteHandler::DeleteImage(Image &Img)
{
    map<int, Image*>::iterator it;

    //On cherche l'image demandée
    for(it = stockImages.begin(); it != stockImages.end(); it++)
    {
    //Si on la trouve, on la détruit et on la retire
        if(it->second == &Img)
        {
            delete &Img;
            stockImages.erase(it);
            break;
        }
    }
}

void spriteHandler::DeleteImageWName(Image &Img)
{
    map<string, Image*>::iterator it;

    //On cherche l'image demandée
    for(it = stockImagesWName.begin(); it != stockImagesWName.end(); it++)
    {
    //Si on la trouve, on la détruit et on la retire
        if(it->second == &Img)
        {
            delete &Img;
            stockImagesWName.erase(it);
            break;
        }
    }
}


void spriteHandler::DeleteImage(const int& ImageLink)
{
    map<int, Image*>::iterator it;

    it = stockImages.find(ImageLink);

    if(it != stockImages.end())
    {
        if(it->second != NULL)
        {
            delete (it->second);
            stockImages.erase(it);
        }
    }
}

void spriteHandler::DeleteImageWName(const string& ImageLink)
{
    map<string, Image*>::iterator it;

    it = stockImagesWName.find(ImageLink);

    if(it != stockImagesWName.end())
    {
        if(it->second != NULL)
        {
            delete (it->second);
            stockImagesWName.erase(it);
        }
    }
}
