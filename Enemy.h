//
//  Enemy.h
//  Launch
//
//  Created by Peter Doe on 4/10/18.
//  Copyright © 2018 Peter Doe. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "Color.h"
#include "SDL_Plotter.h"
#include "Rectangle.h"
#include "Texture.h"
#include <iostream>
#include <ctime>

using namespace std;

//Global Variable
const double CONSTANT = 3.14159;

const int INCREMENT = 10;

const int SIZE_OF_HITBOX = 30;

class Enemy
{
private:
    //radius
    double radius;
    
    //Color
    Color enemyColor;
    
    //Center
    int x, y;
    
    //Hitbox
    Rectangle hitbox;
    
    //health
    int health;
    
public:
    Enemy();  //Default constructor
    Enemy(int nx, int ny, double nr, int nhealth); //Constructor with Point object and radius parameters
    
    //Setters
    void setRadius(const double);
    void setColor(const Color&);
    void setX(int nx);
    void setY(int ny);
    
    void setHitboxUpperLeftX(Rectangle& box, int newX);
    void setHitboxUpperLeftY(Rectangle& box, int newY);
    void setHitboxLowerRightX(Rectangle& box, int newX);
    void setHitboxLowerRightY(Rectangle& box, int newY);
    
    //Getters
    double getRadius() const;
    Color  getColor() const;
    int getX();
    int getY();
    
    //Drawers
    void draw(SDL_Plotter& g) const;
    void drawHitboxEnemy(SDL_Plotter& g);

    //Movers
    void moveEnemy(char direction);
    void specialMove();
};

Enemy::Enemy()  //Default constructor
{
    x = 300;
    y = 350;
    radius = 10;
    enemyColor = Color(220, 20, 20);
    
    hitbox.setUpperLeftX(x + SIZE_OF_HITBOX);
    hitbox.setUpperLeftY(y + SIZE_OF_HITBOX);
    hitbox.setLowerRightX(x + SIZE_OF_HITBOX);
    hitbox.setLowerRightY(y + SIZE_OF_HITBOX);
}

Enemy::Enemy(int nx, int ny, double nr, int nhealth)
{
    x = nx;
    y = ny;
    radius = nr;
    health = nhealth;
    enemyColor = Color(220, 20, 20);
    
    Color hitBoxColor(150, 160, 170);
    
    hitbox.setUpperLeftX(x - SIZE_OF_HITBOX);
    hitbox.setUpperLeftY(y - SIZE_OF_HITBOX);
    hitbox.setLowerRightX(x + SIZE_OF_HITBOX);
    hitbox.setLowerRightY(y + SIZE_OF_HITBOX);
    hitbox.setColorRectangle(hitBoxColor);
}

void Enemy::setRadius(const double r)
{
    radius = r;
}

void Enemy::setColor(const Color& c)
{
    enemyColor = c;
}

void Enemy::setX(int nx)
{
    x = nx;
}

void Enemy::setY(int ny)
{
    y = ny;
}

void Enemy::setHitboxUpperLeftX(Rectangle& box, int newX)
{
    box.setUpperLeftX(newX);
}

void Enemy::setHitboxUpperLeftY(Rectangle& box, int newY)
{
    box.setUpperLeftY(newY);
}

void Enemy::setHitboxLowerRightX(Rectangle& box, int newX)
{
    box.setLowerRightX(newX);
}

void Enemy::setHitboxLowerRightY(Rectangle& box, int newY)
{
    box.setLowerRightY(newY);
}


double Enemy::getRadius() const
{
    return radius;
}

Color  Enemy::getColor() const
{
    return enemyColor;
}

int Enemy::getX()
{
    return x;
}

int Enemy::getY()
{
    return y;
}

void Enemy::draw(SDL_Plotter& g) const
{
    for(int newX = -radius; newX <= radius; newX++)
    {
        for(int newY = -radius; newY <= radius; newY++)
        {
            if(sqrt(newX*newX + newY*newY <= radius))
            {
                g.plotPixel(x + newX, y + newY, enemyColor.R, enemyColor.G, enemyColor.B);
                g.plotPixel(x + newX,y - newY, enemyColor.R, enemyColor.G, enemyColor.B);
            }
        }
    }
}

void Enemy::drawHitboxEnemy(SDL_Plotter& g)
{
    for(int y = hitbox.getUpperLeftY(); y <= hitbox.getLowerRightY(); y++)
    {
        for(int x = hitbox.getUpperLeftX(); x <= hitbox.getLowerRightX(); x++)
        {
            g.plotPixel(x, y, hitbox.getColorRed(), hitbox.getColorGreen(), hitbox.getColorBlue());
        }
    }
}


void Enemy::moveEnemy(char direction)
{
    switch (toupper(direction))
    {
        case 'W':
            setY(getY() - 5);
            break;
        case 'S':
            setY(getY() + 5);
            break;
        case 'A':
            setX(getX() - 5);
            break;
        case 'D':
            setX(getX() + 5);
            break;
    }
}

void Enemy::specialMove()
{
    
    static int k = 0;

    
        if(k < 10 && k % 2 == 0)
        {
            setY(getY() - INCREMENT);
        }

        if(k < 10 && k % 2 == 1)
        {
            setX(getX() + INCREMENT);
        }

        if(k >= 10 && k % 2 == 0)
        {
            setY(getY() + INCREMENT);
        }

        if(k >= 10 && k % 2 == 1)
        {
            setX(getX() + INCREMENT);
        }
        
        k++;
}

#endif /* Enemy_h */
