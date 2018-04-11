#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include <iostream>
using namespace std;

struct Rectangle
{
    //Public data
    int UpperLeftX;
    int UpplerLeftY;
    int LowerRightX;
    int LowerLeftY;
    Color rectangleColor;

    //Setter
    void setUpperLeftX(int);
    void setUpplerLeftY(int);
    void setLowerRightX(int);
    void setLowerLeftY(int);
    void setColorRectangle(const Color&);

    //Getter
    int getUpperLeftX();
    int getUpplerLeftY();
    int getLowerRightX();
    int getLowerLeftY();

    //Constructor
    Rectangle();
    Rectangle(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerLeftY);

    void drawRectangle(SDL_Plotter& r);
};

//Constructor
Rectangle::Rectangle()
{
    UpperLeftX = 10
    UpplerLeftY = 10;
    LowerRightX = 5;
    LowerLeftY = 5;
    Color rectangleColor = Color(100,100,100);

}

Rectangle::Rectangle(int ULX, int ULY, int LRX, int LLY)
{
    UpperLeftX = ULX;
    UpplerLeftY = ULY;
    LowerRightX = LRX;
    LowerLeftY = LLY;
    Color rectangleColor = Color(100,100,100);
}

//Setter
void Rectangle::setUpperLeftX(int ULX)
{
    UpperLeftX = ULX;
}
void Rectangle::setUpplerLeftY(int ULY)
{
    UpperLeftY = ULY;
}
void Rectangle::setLowerRightX(int LRX)
{
    LowerRightX = LRX;
}
void Rectangle::setLowerLeftY(int LLY)
{
    LowerLeftY = LLY;
}

void Rectangle::setColorRectangle(const Color& c)
{
    rectangleColor = c;
}


//Getter
int Rectangle::setUpperLeftX()
{
    return UpperLeftX;
}
int Rectangle::setUpplerLeftY()
{
    return UpperLeftY;
}
int Rectangle::setLowerRightX()
{
    return LowerRightX;
}
int Rectangle::setLowerLeftY()
{
    return LowerLeftY;
}

void drawRectangle(SDL_Plotter& r)
{
    for(int y = upperLeftY; y <= lowerRightY; y++)
    {
        for(int x = upperLeftX; x <= lowerRightX; x++)
        {
            g.plotPixel(x, y, color.R, color.G, color.B);
        }
    }
}

#endif // RECTANGLE_H_INCLUDED
