
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "mapSyst.hpp"

#include <iostream>

using namespace sf;
using namespace std;

class mapHandler
{
    private:
        static mapHandler *singleton;
        mapHandler();

        mapSyst mapCenter;

    public:

        static mapHandler *getInstance()
        {
            if (!singleton)
            {
                singleton = new mapHandler();
                cout<<"Creation du singleton mapHandler reussi\n\n"<<endl;
            }
            return singleton;
        }

        void afficherAll(RenderWindow &fenAffichage);
};
