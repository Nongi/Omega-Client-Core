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

        map<string, Image*> stockImagesWName;
        map<int, Image*> stockImages;

        /*
        //Ensemble de map pour permettre des recherches plus rapides et spécifique au région
        map<string, Image*> stockPrimaire;
        map<string, Image*> stockStatique;
        */

        bool SearchImage(const int &ImageLink, Image* &ImgTemp);
        bool SearchImageWName(const string &ImageLink, Image* &ImgTemp);
        Image *CreateImage(const int &ImageLink);
        Image *CreateImageWName(const string &ImageLink);
        void loadSprites();
        void loadSpritesWName();


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
        Image *getImage(const int &ImageLink);

        void DeleteImage(Image &Img);
        void DeleteImage(const int& ImageLink);

        void DeleteImageWName(Image &Img);
        void DeleteImageWName(const string& ImageLink);

};


