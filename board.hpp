//Include sfml
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//Include system
#include <iostream>
#include <vector>


class board
{
    private:
        //Généralité
        float posX,posY,hauteur,largeur;
        sf::Shape Rect;
        //Fond
        sf::Color background; //quatre composantes 8bits rouge/vert/bleu/alpha

        //Contour
        sf::Color contour;
        float epaisseurContour;

        //Texte du cadre
        sf::String boardText;
        float textPosX, textPosY;
        int textPosition;// 0 = haut gauche, 1 = haut centre, 2 = haut droite, 3 = centre gauche, 4 = centre centre, 5 = centre droite...

        void calculPosText();
        void updatePosText();
    public:
        board();
        board(float posXIn,float posYIn,float hauteurIn,float largeurIn);
        void init(float posXIn,float posYIn,float hauteurIn,float largeurIn,sf::Color boardColorIn,std::string textIn,float taillePolice, sf::Color textColorIn,float outLineSize,sf::Color outLineColor);
        //Setters and getters

        //Using methods of the board
        void moveBoard(float movX,float movY);

        //Using methods of the boardText
        void setText(sf::String textIn);
        void setText(std::string textIn);

        void affiche(sf::RenderWindow &fenAffichage);
};
