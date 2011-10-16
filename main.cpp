#include <iostream>
#include "noyau.hpp"

using namespace std;

int main()
{
    noyau *centerOfGame = noyau::getInstance();
    centerOfGame->run();
    return 0;
}
