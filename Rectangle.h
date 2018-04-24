#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include "Point.h"
#include <iostream>
using namespace std;

const int INTRO_MOVE_INCREMENT = 4;
const int MOVE_RECTANGLE_INCREMENT = 20;
const int MOVE_LEFT_OR_RIGHT_INCREMENT = 3;
const int ATTACK_MOVE_INCREMENT = 1;

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
    //Setters
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
    
    //Constructors
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
    void attackMove(SDL_Plotter& g);
    //void attackMove(SDL_Plotter& g, bool right);
    
    void moveEnemyRight();
    void moveEnemyLeft();

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
    
}

Rectangle::Rectangle(Rectangle& other)
{
    UpperLeftX = other.getUpperLeftX();
    UpperLeftY = 550;
    LowerRightX = other.getLowerRightX();
    LowerRightY = 580;
}


Rectangle::Rectangle(int ULX, int ULY, int LRX, int LLY)
{
    UpperLeftX = ULX;
    UpperLeftY = ULY;
    LowerRightX = LRX;
    LowerRightY = LLY;
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
                setUpperLeftX(getUpperLeftX() - MOVE_RECTANGLE_INCREMENT);
                setLowerRightX(getLowerRightX() - MOVE_RECTANGLE_INCREMENT);
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
                setLowerRightX(getLowerRightX() + MOVE_RECTANGLE_INCREMENT);
                setUpperLeftX(getUpperLeftX() + MOVE_RECTANGLE_INCREMENT);
            }
            break;
    }
}


void Rectangle::moveLaserUp(SDL_Plotter& g)
{
    setUpperLeftY(getUpperLeftY() - 3);
    setLowerRightY(getLowerRightY() - 3);
}

void Rectangle::moveLaserDown(SDL_Plotter& g)
{
    setUpperLeftY(getUpperLeftY() + 3);
    setLowerRightY(getLowerRightY() + 3);
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

void Rectangle::attackMove(SDL_Plotter& g)
{
    setUpperLeftY(getUpperLeftY() + ATTACK_MOVE_INCREMENT);
    setLowerRightY(getLowerRightY() + ATTACK_MOVE_INCREMENT);
}


void Rectangle::moveEnemyRight()
{
    setUpperLeftX(getUpperLeftX() + MOVE_LEFT_OR_RIGHT_INCREMENT);
    setLowerRightX(getLowerRightX() + MOVE_LEFT_OR_RIGHT_INCREMENT);
}

void Rectangle::moveEnemyLeft()
{
    setUpperLeftX(getUpperLeftX() - MOVE_LEFT_OR_RIGHT_INCREMENT);
    setLowerRightX(getLowerRightX() - MOVE_LEFT_OR_RIGHT_INCREMENT);
}

bool Rectangle::enemyCollision(Rectangle laser[], int m)
{
    bool isCollision = false;
    
    if( laser[m].getUpperLeftY() <= getLowerRightY()
         && (laser[m].getLowerRightY() >= getUpperLeftY() )
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
        && (laser[m].getLowerRightY() <= getUpperLeftY() )
        && ( laser[m].getUpperLeftX() <= getLowerRightX() )
        && ( laser[m].getLowerRightX() >= getUpperLeftX() )
        )
    {
        isCollision = true;
    }
    return isCollision;
}



#endif // RECTANGLE_H_INCLUDED
