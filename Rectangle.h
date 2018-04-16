#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include "Point.h"
#include <iostream>
using namespace std;

class Rectangle
{
    //Public data
    private:
      int UpperLeftX;
      int UpperLeftY;
      int LowerRightX;
      int LowerRightY;
      Color rectangleColor;

    public:
      //Setter
      void setUpperLeftX(int);
      void setUpperLeftY(int);
      void setLowerRightX(int);
      void setLowerRightY(int);
      void setColorRectangle(const Color&);

      //Getter
      int getUpperLeftX();
      int getUpperLeftY();
      int getLowerRightX();
      int getLowerRightY();
      int getColorRed();
      int getColorGreen();
      int getColorBlue();

      //Constructor
      Rectangle();
      Rectangle(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerRightY);
      Rectangle(Rectangle& other);

      void drawRectangle(SDL_Plotter& r);
      bool collision(Sphere& );
      void moveRectangle(char direction);
      bool collision(Rectangle& );
};


//Constructor
Rectangle::Rectangle()
{
    UpperLeftX = 2;
    UpperLeftY = 2;
    LowerRightX = 1;
    LowerRightY = 1;
    Color rectangleColor = Color(200,200,200);

}

Rectangle::Rectangle(Rectangle& other)
{
    UpperLeftX = other.getUpperLeftX();
    UpperLeftY = 550;
    LowerRightX = other.getLowerRightX();
    LowerRightY = 580;
    Color rectangleColor = Color(200,200,200);
}


Rectangle::Rectangle(int ULX, int ULY, int LRX, int LLY)
{
    UpperLeftX = ULX;
    UpperLeftY = ULY;
    LowerRightX = LRX;
    LowerRightY = LLY;
    Color rectangleColor = Color(500,500,500);
}

//Setter
void Rectangle::setUpperLeftX(int ULX)
{
    UpperLeftX = ULX;
}
void Rectangle::setUpperLeftY(int ULY)
{
    UpperLeftY = ULY;
}
void Rectangle::setLowerRightX(int LRX)
{
    LowerRightX = LRX;
}
void Rectangle::setLowerRightY(int LLY)
{
    LowerRightY = LLY;
}

void Rectangle::setColorRectangle(const Color& d)
{
    rectangleColor = d;
}


//Getter
int Rectangle::getUpperLeftX()
{
    return UpperLeftX;
}
int Rectangle::getUpperLeftY()
{
    return UpperLeftY;
}
int Rectangle::getLowerRightX()
{
    return LowerRightX;
}
int Rectangle::getLowerRightY()
{
    return LowerRightY;
}

int Rectangle::getColorRed()
{
    return rectangleColor.R;
}

int Rectangle::getColorGreen()
{
    return rectangleColor.G;
}

int Rectangle::getColorBlue()
{
    return rectangleColor.B;
}


void Rectangle::drawRectangle(SDL_Plotter& g)
{
    for(int y = getUpperLeftY(); y <= getLowerRightY(); y++)
    {
        for(int x = getUpperLeftX(); x <= getLowerRightX(); x++)
        {
            g.plotPixel(x, y, rectangleColor.R, rectangleColor.G, rectangleColor.B);
        }
    }
}

void Rectangle::moveRectangle(char direction)
{
    switch (toupper(direction))
    {
        case 'A':
            if(getUpperLeftX() == 0)
            {
                setUpperLeftX(getUpperLeftX());
                setLowerRightX(getLowerRightX());
            }
            else
            {
                setUpperLeftX(getUpperLeftX() - 5);
                setLowerRightX(getLowerRightX() - 5);
            }
            break;
        case 'D':
            if(getLowerRightX() == 700)
            {
                setLowerRightX(getLowerRightX());
                setUpperLeftX(getUpperLeftX());
            }
            else
            {
                setLowerRightX(getLowerRightX() + 5);
                setUpperLeftX(getUpperLeftX() + 5);
            }
            break;
    }
}


bool Rectangle::collision(Rectangle& laser)
{
    bool isCollision = false;

    if(getLowerRightY() >= laser.getUpperLeftY())
    {
      isCollision = true;
    }

  return isCollision;
}


#endif // RECTANGLE_H_INCLUDED
