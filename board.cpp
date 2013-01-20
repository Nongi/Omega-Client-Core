//--------------------------------Include project
#include "board.hpp"
#include "spriteHandler.hpp"
#include "boardForm.hpp"
//--------------------------------Include SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//--------------------------------Include Systeme
#include <iostream>

#include "elementMap.hpp"
#include "bddInternalHandler.hpp"
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

board::board(){
    Rect = sf::Shape::Rectangle(200,200,260,260,sf::Color(0,0,0));
    boardText = sf::String("fuck this",sf::Font::GetDefaultFont(),30);
    updatePosText();
}

board::board(float posXIn, float posYIn, float hauteurIn, float largeurIn)
{


}

void board::init(float posXIn,float posYIn,float hauteurIn,float largeurIn,sf::Color boardColorIn,std::string textIn,float taillePolice, sf::Color textColorIn,float outLineSize,sf::Color outLineColor)
{
    Rect = sf::Shape::Rectangle(posXIn,posYIn,hauteurIn,largeurIn,boardColorIn,outLineSize,outLineColor);
    boardText = sf::String(textIn,sf::Font::GetDefaultFont(),taillePolice);
    boardText.SetColor(textColorIn);
    updatePosText();
}

//--------------------------------------------

void board::moveBoard(float movX,float movY){

}

void board::setText(sf::String textIn)
{
    boardText=textIn;
    updatePosText();
}

void board::setText(std::string textIn)
{
    boardText=sf::String(textIn,sf::Font::GetDefaultFont(),30);
}

void board::affiche(sf::RenderWindow &fenAffichage)
{
    fenAffichage.Draw(Rect);
    fenAffichage.Draw(boardText);
}

void board::calculPosText()
{

}

void board::updatePosText()
{
    calculPosText();
    boardText.Move(textPosX,textPosY);
}


