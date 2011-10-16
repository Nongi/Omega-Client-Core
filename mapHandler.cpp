#include "mapHandler.hpp"
#include "spriteHandler.hpp"

using namespace sf;
using namespace std;

mapHandler *mapHandler::singleton = NULL;

mapHandler::mapHandler()
{
    mapCenter.initPrimaire("5000000");
}

void mapHandler::afficherAll(RenderWindow &fenAffichage)
{
    mapCenter.afficherAll(fenAffichage);
}
