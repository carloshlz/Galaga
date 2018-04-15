#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include <iostream>
using namespace std;
class Ship
{
    //Public data
    private:
      int UpperLeftX;
      int UpperLeftY;
      int LowerRightX;
      int LowerRightY;
      Color rectangleColor;

      int centerX;
      int centerY;

    public:
      //Setter
      void setUpperLeftX(int);
      void setUpperLeftY(int);
      void setLowerRightX(int);
      void setLowerRightY(int);
      void setColorRectangle(const Color&);
      void setCenterX(int);
      void setCenterY(int);

      //Getter
      int getUpperLeftX();
      int getUpperLeftY();
      int getLowerRightX();
      int getLowerRightY();
      int getCenterX();
      int getCenterY();

      //Constructor
      Ship();
      Ship(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerRightY);

      void drawRectangle(SDL_Plotter& r);
      bool collision(Sphere& );
      void moveShip(char direction);
};

//Constructor
Ship::Ship()
{
    UpperLeftX = 0;
    UpperLeftY = 0;
    LowerRightX = 0;
    LowerRightY = 0;
    Color rectangleColor = Color(200,200,200);

    centerX = (getLowerRightX() - getUpperLeftX())/2.0;
    centerY = (getLowerRightY() - getUpperLeftY())/2.0;
}

Ship::Ship(int ULX, int ULY, int LRX, int LLY)
{
    UpperLeftX = ULX;
    UpperLeftY = ULY;
    LowerRightX = LRX;
    LowerRightY = LLY;
    Color rectangleColor = Color(500,500,500);
}

//Setter
void Ship::setUpperLeftX(int ULX)
{
    UpperLeftX = ULX;
}
void Ship::setUpperLeftY(int ULY)
{
    UpperLeftY = ULY;
}
void Ship::setLowerRightX(int LRX)
{
    LowerRightX = LRX;
}
void Ship::setLowerRightY(int LLY)
{
    LowerRightY = LLY;
}

void Ship::setColorRectangle(const Color& d)
{
    rectangleColor = d;
}


//Getter
int Ship::getUpperLeftX()
{
    return UpperLeftX;
}
int Ship::getUpperLeftY()
{
    return UpperLeftY;
}
int Ship::getLowerRightX()
{
    return LowerRightX;
}
int Ship::getLowerRightY()
{
    return LowerRightY;
}

void Ship::drawRectangle(SDL_Plotter& g)
{
    for(int y = getUpperLeftY(); y <= getLowerRightY(); y++)
    {
        for(int x = getUpperLeftX(); x <= getLowerRightX(); x++)
        {
            g.plotPixel(x, y, rectangleColor.R, rectangleColor.G, rectangleColor.B);
        }
    }
}

int Ship::getCenterX()
{
  return centerX;
}
int Ship::getCenterY()
{
  return centerY;
}

void Ship::setCenterX(int setX)
{
  centerX = setX;
}
void Ship::setCenterY(int setY)
{
  centerY = setY;
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
