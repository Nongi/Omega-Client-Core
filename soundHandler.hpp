#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class soundHandler
{
    private :

        static soundHandler *singleton;
        soundHandler();
        ~soundHandler();

        map<string, SoundBuffer*> stockSounds;

        bool SearchSound(const string &SoundLink, SoundBuffer* &SoundTemp);
        SoundBuffer *CreateSound(const string &SoundLink);
        void loadSounds();

    public:

        static soundHandler *getInstance()
        {
            if (!singleton)
            {
                singleton = new soundHandler();
                cout<<"Creation du singleton soundHandler reussi\n\n"<<endl;
            }
            return singleton;
        }



        SoundBuffer *getSound(const string &SoundLink);

        void DeleteSound(SoundBuffer &Son);
        void DeleteSound(const string& SoundLink);

};


