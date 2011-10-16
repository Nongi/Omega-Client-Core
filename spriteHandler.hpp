#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class spriteHandler
{
    private :

        static spriteHandler *singleton;
        spriteHandler();
        ~spriteHandler();

        map<string, Image*> stockImages;

        /*
        //Ensemble de map pour permettre des recherches plus rapides et spécifique au région
        map<string, Image*> stockPrimaire;
        map<string, Image*> stockStatique;
        */

        bool SearchImage(const string &ImageLink, Image* &ImgTemp);
        Image *CreateImage(const string &ImageLink);
        void loadSprites();


    public:

        static spriteHandler *getInstance()
        {
            if (!singleton)
            {
                singleton = new spriteHandler();
                cout<<"Creation du singleton spriteHandler reussi\n\n"<<endl;
            }
            return singleton;
        }



        Image *getImage(const string &ImageLink);

        void DeleteImage(Image &Img);
        void DeleteImage(const string& ImageLink);

};


