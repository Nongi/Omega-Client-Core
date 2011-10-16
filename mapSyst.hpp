//#include "spriteHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "elementMap.hpp"

#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class mapSyst
{
    //Map composé de sprite de 16*16 800*600 (50*37,5)
    private :

        vector<elementMap*> couchePrimaire;
        vector<string> coucheStatique;
        vector<string> coucheDynamique;

        int largeur,longueur;

        int getLargeur(string mapPrimaire);
        int getLongueur(string mapPrimaire);

    public :
        mapSyst();
        mapSyst(string idMap);
        ~mapSyst();

        void initPrimaire(string idMap);
        void afficherAll(RenderWindow &fenAffichage);
};
