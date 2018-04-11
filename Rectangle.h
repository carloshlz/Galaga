#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
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

      //Constructor
      Rectangle();
      Rectangle(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerRightY);

      void drawRectangle(SDL_Plotter& r);
      bool collision(Sphere& );
};

//Constructor
Rectangle::Rectangle()
{
    UpperLeftX = 0;
    UpperLeftY = 0;
    LowerRightX = 0;
    LowerRightY = 0;
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

/*
bool Rectangle::collision(Sphere& s)
{
  bool flag = false;
  for()
  {
    for()
    {
      flag = true;
    }
  }
  return flag;
}
*/

#endif // RECTANGLE_H_INCLUDED
