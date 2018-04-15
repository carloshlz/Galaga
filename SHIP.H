#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "Rectangle.h"
#include "SDL_Plotter.h"
#include <iostream>
using namespace std;

class Ship
{
    private:
        Rectangle spaceCraft;
        int centerX;
        int centerY;

    public:
        Ship();
        void moveShip(char direction);

        void setCenterX(int);
        void setCenterY(int);

        int getCenterX();
        int getCenterY();

};

//Default constructor
Ship::Ship()
{
    centerX = (spaceCraft.getLowerRightX() - spaceCraft.getUpperLeftX())/2.0;
    centerY = (spaceCraft.getLowerRightY() - spaceCraft.getUpperLeftY())/2.0;
}

void Ship::setCenterX(int x)
{
    centerX = x;
}
void Ship::setCenterY(int y)
{
    centerY = y;
}

int Ship::getCenterX()
{
    return centerX;
}
int Ship::getCenterY()
{
    return centerY;
}

void Ship::moveShip(char direction)
{
    switch (toupper(direction))
    {
    case 'A':
        if(getCenterX() <= 5)
        {
            setCenterX(getCenterX());
        }
        else
        {
            setCenterX(getCenterX() - 5);
        }
        break;
    case 'D':
        if(getCenterX() >= 695)
        {
            setCenterX(getCenterX());
        }
        else
        {
            setCenterX(getCenterX() + 5);
        }
        break;
}


#endif // SHIP_H_INCLUDED
