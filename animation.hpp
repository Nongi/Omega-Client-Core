#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>

using namespace std;
using namespace sf;

class animation
{
    private:
        int coordX,coordY;
        float vitesse;

        std::vector<string> listeNameSpritesAnim;
        Sprite spriteCourant;

        int idSpriteCourant;
        bool loop;
        sf::Clock timerC;

        void updateSprite();
        void updateSpriteNumber();


    public:

        animation();
        animation(string idAnim);

        void setModificationPos(int coordXIn,int coordYIn);
        void setPosition(int coordXIn,int coordYIn);


        void afficher(RenderWindow &fenAffichage);

        //Ensemble des fonctions permettant de jouer une animation
        void play();
        void pause();
        void stop();


        void setLoopEnable();
        void setLoopDisable();

        float getTimer();
};
