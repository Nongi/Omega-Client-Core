#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

using namespace std;
using namespace sf;

class musicHandler
{
    private :

        static musicHandler *singleton;
        musicHandler();
        ~musicHandler();

        map<string, Music*> stockMusics;

        bool SearchMusic(const string &MusicLink, Music* &MusicTemp);
        Music *CreateMusic(const string &MusicLink);
        void loadMusics();


    public:

        static musicHandler *getInstance()
        {
            if (!singleton)
            {
                singleton = new musicHandler();
                cout<<"Creation du singleton musicHandler reussi\n\n"<<endl;
            }
            return singleton;
        }

        Music *getMusic(const string &MusicLink);

        void DeleteMusic(Music &Musique);
        void DeleteMusic(const string& MusicLink);

};



