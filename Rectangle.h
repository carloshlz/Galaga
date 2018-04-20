#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include "Point.h"
#include <iostream>
using namespace std;

const int INTRO_MOVE_INCREMENT = 1;

class Rectangle
{
    //Public data
private:
    int UpperLeftX;
    int UpperLeftY;
    int LowerRightX;
    int LowerRightY;
    Color rectangleColor;
    bool surviving;
    Point home;
    
public:
    //Setter
    void setUpperLeftX(int);
    void setUpperLeftY(int);
    void setLowerRightX(int);
    void setLowerRightY(int);
    void setColorRectangle(const Color&);
    void setSurviving(bool);
    void setHome(Point);
    
    //Getter
    int getUpperLeftX();
    int getUpperLeftY();
    int getLowerRightX();
    int getLowerRightY();
    bool getSurviving();
    
    //Constructor
    Rectangle();
    Rectangle(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerRightY);
    Rectangle(Rectangle& other);
    
    //Draw Functions
    void drawRectangle(SDL_Plotter& r);
    
    void eraseRectangle(SDL_Plotter& g);
    
    //Movement
    void moveRectangle(char direction);
    void moveLaserUp(SDL_Plotter& g);
    void moveLaserDown(SDL_Plotter& g);
    void introMove(SDL_Plotter& g, int midLine);
    void attackMove(SDL_Plotter& g, bool right);

    //void drawLaser(SDL_Plotter& g, int , int );
    
    //Collision
    bool enemyCollision(Rectangle laser[], int m);
    bool shipCollision(Rectangle laser[], int m);
    
    
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

void Rectangle::setSurviving(bool a)
{
    surviving = a;
}

void Rectangle::setHome(Point a)
{
    home = a;
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

bool Rectangle::getSurviving()
{
    return surviving;
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

void Rectangle::eraseRectangle(SDL_Plotter& g)
{
    for(int y = getUpperLeftY(); y <= getLowerRightY(); y++)
    {
        for(int x = getUpperLeftX(); x <= getLowerRightX(); x++)
        {
            g.plotPixel(x, y, 255, 255, 255);
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



//TEST Kevin
/*
void Rectangle::drawLaser(SDL_Plotter& g, int falconLeftX , int falconRightX)
{
    for(int y = 585; y <= 595; y++)
    {
        for(int x = falconLeftX; x <= falconLeftX; x++)
        {
            g.plotPixel(x, y, rectangleColor.R, rectangleColor.G, rectangleColor.B);
        }
    }
}
 */


void Rectangle::moveLaserUp(SDL_Plotter& g)
{
    setUpperLeftY(getUpperLeftY() - 1);
    setLowerRightY(getLowerRightY() - 1);
}

void Rectangle::moveLaserDown(SDL_Plotter& g)
{
    setUpperLeftY(getUpperLeftY() + 1);
    setLowerRightY(getLowerRightY() + 1);
}

void Rectangle::introMove(SDL_Plotter& g, int midLine)
{
    if(LowerRightY <= home.y && LowerRightX >= home.x)
    {
        setUpperLeftX(getUpperLeftX() - INTRO_MOVE_INCREMENT);
        setLowerRightX(getLowerRightX() - INTRO_MOVE_INCREMENT);
    }
    else if (LowerRightY <= home.y && LowerRightX < home.x)
    {
        
    }
    else if (LowerRightX >= midLine)
    {
        setUpperLeftX(getUpperLeftX() + INTRO_MOVE_INCREMENT);
        setLowerRightX(getLowerRightX() + INTRO_MOVE_INCREMENT);
        setUpperLeftY(getUpperLeftY() - INTRO_MOVE_INCREMENT);
        setLowerRightY(getLowerRightY() - INTRO_MOVE_INCREMENT);
    }
    else if (LowerRightX < midLine)
    {
        setUpperLeftX(getUpperLeftX() + INTRO_MOVE_INCREMENT);
        setLowerRightX(getLowerRightX() + INTRO_MOVE_INCREMENT);
        setUpperLeftY(getUpperLeftY() + INTRO_MOVE_INCREMENT);
        setLowerRightY(getLowerRightY() + INTRO_MOVE_INCREMENT);
    }
}

void Rectangle::attackMove(SDL_Plotter& g, bool right)
{
    setUpperLeftY(getUpperLeftY() - INTRO_MOVE_INCREMENT);
    setLowerRightY(getLowerRightY() - INTRO_MOVE_INCREMENT);
    if(right)
    {
        setUpperLeftX(getUpperLeftX() + INTRO_MOVE_INCREMENT);
        setLowerRightX(getLowerRightX() + INTRO_MOVE_INCREMENT);
    }
    else
    {
        setUpperLeftX(getUpperLeftX() - INTRO_MOVE_INCREMENT);
        setLowerRightX(getLowerRightX() - INTRO_MOVE_INCREMENT);
    }
}

bool Rectangle::enemyCollision(Rectangle laser[], int m)
{
    bool isCollision = false;
    
    if( (laser[m].getUpperLeftY() <= getLowerRightY() )
       && ( (laser[m].getUpperLeftX() <= getLowerRightX() )
           && ( laser[m].getLowerRightX() >= getUpperLeftX() )  ) )

    {
        isCollision = true;
    }
    return isCollision;
}

bool Rectangle::shipCollision(Rectangle laser[], int m)
{
    bool isCollision = false;
    
    if( (laser[m].getUpperLeftY() >= getLowerRightY() )
        && ( laser[m].getUpperLeftX() <= getLowerRightX() )
        && ( laser[m].getLowerRightX() >= getUpperLeftX() )
        )
    {
        isCollision = true;
    }
    return isCollision;
}


#endif // RECTANGLE_H_INCLUDED
