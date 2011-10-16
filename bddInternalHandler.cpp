#include "bddInternalHandler.hpp"
#include "GestionnaireDB.h"

#include <iostream>
#include <sstream>

using namespace std;

bddInternalHandler *bddInternalHandler::singleton = NULL;

bddInternalHandler::bddInternalHandler()
{
    db = new GestionnaireDB("internal.db");

    /*
    A surtout ne pas oter les parenthese sans changer le nom de la db plz
    db->query("CREATE TABLE Sounds (idSound char(50), PRIMARY KEY(idSound));");
    db->query("INSERT INTO Sounds VALUES('activated');");
    db->query("CREATE TABLE Musics (idMusic char(50), PRIMARY KEY(idMusic));");
    db->query("INSERT INTO Musics VALUES('OverMore');");
    */

    //---------------------------------------------------------------------------------------

    /*db->query("CREATE TABLE Sounds (idSound INTEGER, nameSound char(50), PRIMARY KEY(idSound));");

    db->query("INSERT INTO Sounds VALUES(0,'activated');");

    //---------------------------------------------------------------------------------------

    db->query("CREATE TABLE Musics (idMusic INTEGER, nameMusic char(50), PRIMARY KEY(idMusic));");

    db->query("INSERT INTO Musics VALUES(0,'OverMore');");

    //---------------------------------------------------------------------------------------

    db->query("CREATE TABLE Sprites (idSprite INTEGER, nomSprite CHAR(50), tailleX INTEGER, tailleY INTEGER, coordX INTEGER, coordY INTEGER, PRIMARY KEY(idSprite));");

    db->query("INSERT INTO Sprites VALUES(0,'herbe1',16,16,0,0);");

    db->query("INSERT INTO Sprites VALUES(1,'chemin1',16,16,0,0);");

    db->query("INSERT INTO Sprites VALUES(2,'chemin2',16,16,0,0);");

    db->query("INSERT INTO Sprites VALUES(100,'scientifiqueFront',18,24,0,0);");

    db->query("INSERT INTO Sprites VALUES(101,'scientifiqueBack',18,24,0,0);");

    db->query("INSERT INTO Sprites VALUES(102,'scientifiqueRight',18,24,0,0);");

    db->query("INSERT INTO Sprites VALUES(103,'scientifiqueLeft',18,24,0,0);");

    //---------------------------------------------------------------------------------------

    db->query("CREATE TABLE Map (idMap INTEGER, largeur INTEGER, longueur INTEGER, couchePrimaire CHAR, coucheStatique CHAR, PRIMARY KEY(idMap));");

    db->query("INSERT INTO Map VALUES(5000000,30,30,16,'12,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,28,0,1,1,1,2,16,0','0');");
    */


    //db->query("CREATE TABLE ElementsPrim (idElemPrim INTEGER, codePassage INTEGER, PRIMARY KEY(idElemPrim));");
    //db->query("CREATE TABLE LinkSprite (idElemPrim INTEGER,idSprite INTEGER, PRIMARY KEY(idElemPrim,idSprite));");

}

bddInternalHandler::~bddInternalHandler()
{
    db->close();
}

vector<string> bddInternalHandler::getListeSprites()
{
    vector<string> resultEnd;

    vector<vector<string> > result = db->query("SELECT nomSprite FROM Sprites;");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd.push_back(row.back());
    }

    return resultEnd;

}

vector<string> bddInternalHandler::getListeSounds()
{
    vector<string> resultEnd;
    vector<vector<string> > result = db->query("SELECT nameSound FROM Sounds;");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd.push_back(row.back());
    }
    return resultEnd;

}

vector<string> bddInternalHandler::getListeMusics()
{
    vector<string> resultEnd;

    vector<vector<string> > result = db->query("SELECT nameMusic FROM Musics;");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd.push_back(row.back());
    }
    return resultEnd;

}

/*
    Pour récuper tout les sprites possible de l'élément herbe (idelem = 1)
    vector<string> resultEnd;
    resultEnd=instBddInternalHandler->getListeSpritesElem("1");
    for(vector<string>::iterator i = resultEnd.begin(); i != resultEnd.end();++i)
    {
        cout<<*i<<endl;
    }
*/
vector<string> bddInternalHandler::getListeSpritesElem(string idElement)
{
    vector<string> resultEnd;

    vector<vector<string> > result = db->query("SELECT Sprites.nomSprite FROM Sprites, LinkSprite WHERE Sprites.idSprite=LinkSprite.idSprite AND LinkSprite.idElemPrim="+idElement+";");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd.push_back(row.back());
    }

    return resultEnd;
}

string bddInternalHandler::getSprite(string idSpriteIn)
{
    string resultEnd;
    vector<vector<string> > result = db->query("SELECT nomSprite FROM Sprites WHERE idSprite ="+idSpriteIn+";");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd=row.back();
    }
    return resultEnd;
}

vector<string> bddInternalHandler::getMapPrimaire(string idMap)
{
    string resultTemp;

    vector<vector<string> > result = db->query("SELECT couchePrimaire FROM Map WHERE map.idMap="+idMap+";");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultTemp=row.back();
    }

    string temp="";
    vector<string> resultEnd;

    for(int i=0;i<resultTemp.size();i++)
    {
        if(resultTemp.at(i)==',')
        {
            resultEnd.push_back(temp);
            temp="";
        }
        else
            temp+=resultTemp.at(i);
    }
    resultEnd.push_back(temp);

    return resultEnd;
}

int bddInternalHandler::getMapLargeur(string idMap)
{
    //request pour acquérir la tite largeur de notre map
    string resultEnd;

    vector<vector<string> > result = db->query("SELECT largeur FROM Map WHERE map.idMap="+idMap+";");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd=row.back();
    }
    //convertion du resultat en int
    istringstream iss( resultEnd );
    int largeurMap;
    iss >> largeurMap;

    return largeurMap;
}

int bddInternalHandler::getMapLongueur(string idMap)
{
    //request pour acquérir la tite longueur de notre map
    string resultEnd;

    vector<vector<string> > result = db->query("SELECT longueur FROM Map WHERE map.idMap="+idMap+";");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        resultEnd=row.back();
    }
    //convertion du resultat en int
    istringstream iss( resultEnd );
    int longueurMap;
    iss >> longueurMap;

    return longueurMap;
}

