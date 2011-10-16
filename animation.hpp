#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>

using namespace std;
using namespace sf;

class animation
{
    private:
        int timer,vitesse,coordX,coordY;
        vector<Sprite> listeSpritesAnim;
        int spriteCourant;
        bool loop;

    public:

        animation();
        animation(string idAnim);

        void setModificationPos(int coordXIn,int coordYIn);
        void setPosition(int coordXIn,int coordYIn);


        void afficher(RenderWindow &fenAffichage);

        //Ensemble des fonctions permettant de jouer une animation
        void play();
        void play(int coordXIn, int coordYIn);
        //avec un temp spécifique
        void play(int timeIn);
        void play(int coordXIn, int coordYIn, int timeIn);
        void pause();
        void stop();

        void setLoopEnable();
        void setLoopDisable();

        int getTimer();
};
