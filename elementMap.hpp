//#include "spriteHandler.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class elementMap
{
    //
    private :

         Sprite spriteEltPrim;
         Sprite spriteElt;
         int coordX;
         int coordY;


    public :
        elementMap();
        elementMap(string idElement);
        elementMap(string idElement,int coordXIn,int coordYIn);
        elementMap(int idElement,int coordXIn,int coordYIn);
        ~elementMap();

        void affiche(RenderWindow &fenAffichage);
};


