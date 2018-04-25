/*
 *  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
 *  Assignment Title: Final Project.
 *  Assignment Description: Write your own interpretation of Galaga
 *  Due Date: 4/25/18
 *  Date Created: 04/05/18
 *  Date Last Modified: 4/24/28
 */

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Color.h"
#include "SDL_Plotter.h"
#include "Point.h"
#include <iostream>
using namespace std;

//Global variables.
const int INTRO_MOVE_INCREMENT = 6;
const int MOVE_RECTANGLE_INCREMENT = 20;
const int MOVE_LEFT_OR_RIGHT_INCREMENT = 6;
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
    int lives;

public:

    //Setters
/*
Description: sets the upper left x value of the rectangle to the defined int
Return: void
Precondition: a valid integer exists
Postcondition: all values remain unchanged
*/
    void setUpperLeftX(int);

/*
Description: sets the upper left y value of the rectangle to the defined int
Return: void
Precondition: a valid integer exists
Postcondition: all values remain unchanged
*/
    void setUpperLeftY(int);

/*
Description: sets the lower left x value of the rectangle to the defined int
Return: void
Precondition: a valid integer exists
Postcondition: all values remain unchanged
*/
    void setLowerRightX(int);

/*
Description: sets the lower left y value of the rectangle to the defined int
Return: void
Precondition: a valid integer exists
Postcondition: all values remain unchanged
*/
    void setLowerRightY(int);

/*
Description: sets the rectangle to a defined/given color
Return: void
Precondition: a valid constant Color object exists
Postcondition: color object changed, all other values remain unchanged
*/
    void setColorRectangle(const Color&);

/*
Description: sets surviving value to true, making any inactive lasers, active
Return: void
Precondition: a valid boolean exists
Postcondition: all values remain unchanged
*/
    void setSurviving(bool);

/*
Description: sets the assigned point to which enemy objects rest
Return: void
Precondition: a valid Point object exists
Postcondition: all other values remain unchanged
*/
    void setHome(Point);

/*
Description: sets the amount of lives with the given/defined int value
Return: void
Precondition: a valid integer exists
Postcondition: all values remain unchanged
*/
    void setLives(int);


    //Getters
/*
Description: returns the rectangle’s upper left x value
Return: int
Precondition: none
Postcondition: all values remain unchanged
*/
    int getUpperLeftX();

/*
Description: returns the rectangle’s upper left y value
Return: int
Precondition: none
Postcondition: all values remain unchanged
*/
    int getUpperLeftY();

/*
Description: returns the rectangle’s lower left x value
Return: int
Precondition: none
Postcondition: all values remain unchanged
*/
    int getLowerRightX();

/*
Description: returns the rectangle’s lower left y value
Return: int
Precondition: none
Postcondition: all values remain unchanged
*/
    int getLowerRightY();

/*
Description: returns the surviving boolean value
Return: bool
Precondition: none
Postcondition: all values remain unchanged
*/
    bool getSurviving();

/*
Description: returns the amount of lives
Return: int
Precondition: none
Postcondition: all values remain unchanged
*/
    int getLives();


    //Constructors
/*
Description: default constructor that sets the rectangle’s upper left coordinates to
(2,2) and the lower right coordinates to (1,1)
Return: none
Precondition: none
Postcondition: all values remain unchanged
*/
    Rectangle();

/*
Description: custom constructor that sets the rectangle’s upper
and lower left point values to the given/defined values
Return: none
Precondition: 4 valid integers exist
Postcondition: all values remain unchanged
*/
    Rectangle(int UpperLeftX, int UpperLeftY, int LowerRightX, int LowerRightY);

/*
Description: custom constructor that sets an object’s upper
and lower left point values to another object’s
Return: none
Precondition: another valid rectangle object exists
Postcondition: other object value changed, rest of values remain
unchanged
*/
    Rectangle(Rectangle& other);


    //Draw Functions
/*
Description: moves rectangle location
Return: void
Precondition: a valid SDL_Plotter object exists
Postcondition: r object changed
*/
    void drawRectangle(SDL_Plotter& r);

/*
Description: erases rectangle location and prints black
Return: void
Precondition: a valid SDL_Plotter object exists
Postcondition: g object changed
*/
    void eraseRectangle(SDL_Plotter& g);


    //Movement
/*
Description: moves rectangle left or right depending on user input
Return: void
Precondition: a valid char exists
Postcondition: all values remain unchanged
*/
    void moveRectangle(char direction);

/*
Description: moves the laser upwards (coming from ship)
Return: void
Precondition: a valid SDL_Plotter object exists
Postcondition: g object changed
*/
    void moveLaserUp(SDL_Plotter& g);

/*
Description: moves the laser downwards (coming from enemies)
Return: void
Precondition: a valid SDL_Plotter object exists
Postcondition: g object changed
*/
    void moveLaserDown(SDL_Plotter& g);

/*
Description: moves/guides the enemy objects to the given display midline value
Return: void
Precondition: a valid SDL_Plotter object and int exists
Postcondition: g object changed, ints remain unchanged
*/
    void introMove(SDL_Plotter& g, int midLine);

/*
Description: moves the enemy objects downwards
Return: void
Precondition: a valid SDL_Plotter object exists
Postcondition: g object changed
*/
    void attackMove(SDL_Plotter& g);

/*
Description: moves the enemy objects to the right
Return: void
Precondition: none
Postcondition: none, values remain unchanged
*/
    void moveEnemyRight();

/*
Description: moves the enemy objects to the left
Return: void
Precondition: none
Postcondition: none, values remain unchanged
*/
    void moveEnemyLeft();


    //Collision
/*
Description: detects whether an enemy ship is hit by player’s laser
Return: bool
Precondition: a valid rectangle array of objects and int exists
Postcondition: all values remain unchanged
*/
    bool enemyCollision(Rectangle laser[], int m);

/*
Description: detects whether the player ship is hit by enemy lasers
Return: bool
Precondition: a valid rectangle array of objects and int exists
Postcondition: all values remain unchanged
*/
    bool shipCollision(Rectangle laser[], int m);
};


#endif // RECTANGLE_H_INCLUDED
