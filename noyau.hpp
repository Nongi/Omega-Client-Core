#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>

using namespace std;

class noyau
{
    private :
        static noyau *singleton;

        noyau ();


    public:
        static noyau *getInstance()
        {
            if (!singleton)
            {
                singleton = new noyau();
                std::cout<<"Eveil du Noyau reussi\n\n"<<std::endl;
            }
            return singleton;
        }

        void run();
};

