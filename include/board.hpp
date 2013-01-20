#ifndef BOARD_H
#define BOARD_H


class board
{
    public:
        board();
        virtual ~board();
        float GetposX() { return posX; }
        void SetposX(float val) { posX = val; }
        float GetposY() { return posY; }
        void SetposY(float val) { posY = val; }
        sf::Color GetcolorOn() { return colorOn; }
        void SetcolorOn(sf::Color val) { colorOn = val; }
        sf::Color GetcolorArround() { return colorArround; }
        void SetcolorArround(sf::Color val) { colorArround = val; }
        float Getthickness() { return thickness; }
        void Setthickness(float val) { thickness = val; }
    protected:
    private:
        float posX;
        float posY;
        sf::Color colorOn;
        sf::Color colorArround;
        float thickness;
};

#endif // BOARD_H
