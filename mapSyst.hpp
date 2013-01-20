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


    public :
        mapSyst();
        mapSyst(string idMap);
        mapSyst(int idMap);
        ~mapSyst();

        void initPrimaire(string idMap);
        void initPrimaire(int idMap);
        void afficherAll(RenderWindow &fenAffichage);

        int getLargeur();
        int getLongueur();
};
