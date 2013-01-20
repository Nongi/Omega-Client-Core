//include project
#include "GestionnaireDB.h"
//include système
#include <iostream>
#include <map>

using namespace std;

class bddInternalHandler
{
    private:

        static bddInternalHandler *singleton;
        bddInternalHandler();
        ~bddInternalHandler();

        GestionnaireDB *db;

    public:

        static bddInternalHandler *getInstance()
        {
            if (!singleton)
            {
                singleton = new bddInternalHandler();
                cout<<"Creation du singleton bddInternalHandler reussi\n\n"<<endl;
            }
            return singleton;
        }

        vector<string> getListeSounds();
        vector<string> getListeMusics();

        //Gestion des sprites
        string getSpriteName(string idSpriteIn);
        string getSpriteName(int idSpriteIn);

        vector<int> getListeSprites();
        vector<string> getListeSpritesName();

        vector<int> getListeSpritesElem(int idElement);
        vector<int> getListeSpritesElem(string idElement);

        vector<string> getListeSpritesNameElem(string idElement);

        //Gestion des maps
        vector<string> getMapPrimaire(string idMap);
        int getMapLargeur(string idMap);
        int getMapLongueur(string idMap);

        vector<string> getMapPrimaire(int idMap);
        int getMapLargeur(int idMap);
        int getMapLongueur(int idMap);

        //Gestion des animations
        map<int, string> getAnimation(string idAnim);
        float getVitesseAnimation(string idAnim);
        map<int, string> getAnimation(int idAnim);
        float getVitesseAnimation(int idAnim);



};
