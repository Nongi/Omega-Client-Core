#include "GestionnaireDB.h"
#include <iostream>

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

        vector<string> getListeSprites();
        vector<string> getListeSounds();
        vector<string> getListeMusics();

        vector<string> getListeSpritesElem(string idElement);

        string getSprite(string idSpriteIn);

        vector<string> getMapPrimaire(string idMap);
        int getMapLargeur(string idMap);
        int getMapLongueur(string idMap);



};
