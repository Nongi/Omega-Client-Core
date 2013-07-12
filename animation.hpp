#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>


class animation
{
    private:
        std::string idAnimation;
        int coordX,coordY;
        float vitesse;

        std::vector<std::string> listeNameSpritesAnim;
        std::string spriteBase;
        sf::Sprite spriteCourant;

        int idSpriteCourant;
        bool loop,run;
        sf::Clock timerC;

        void updateSprite();
        void updateSpriteNumber();


    public:

        animation();
        animation(std::vector<std::string> listeSpriteIn,float vitIn);
        animation(std::string idAnim);
        animation(std::string idAnim, bool loopIn);

        void initAnimation(std::string idAnim);

        void move(int coordXIn,int coordYIn);
        void setPosition(int coordXIn,int coordYIn);
        void setScale(float xIn,float yIn);


        void afficher(sf::RenderWindow &fenAffichage);

        //Ensemble des fonctions permettant de jouer une animation
        void play();
        void stop();

        void setLoopEnable();
        void setLoopDisable();

        float getTimer();
};
