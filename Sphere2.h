#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

using namespace std;

//Global Variable
const double PIE = 3.14159;

class Sphere
{
private:
    double radius;
    //Point center;
    Color sphereColor;
    
    int x, y;
    
    
public:
    Sphere();  //Default constructor
    Sphere(Point centerObject, double r); //Constructor with Point object and radius parameters
    
    //Setters constant
    void setRadius(const double);
    //void setCenter(const Point&);
    void setColor(const Color&);
    
    void setX(int nx);
    void setY(int ny);
    int getX();
    int getY();
    
    //Getters constant
    double getRadius() const;
    //Point  getCenter() const;
    Color  getColor() const;
    
    
    
    void draw(SDL_Plotter&) const;
    void eraseSphere(SDL_Plotter& g) const;
    
    void moveSphere(char direction);
    
};

Sphere::Sphere()  //Default constructor
{
    x = 300;
    y = 650;
    radius = 10;
    sphereColor = Color(220, 20, 20);
}

Sphere::Sphere(Point centerObject, double r) //Constructor with Point object and radius parameters
{
    x = 300;
    y = 650;
    r = 10;
    sphereColor = Color(220, 20, 20);
}

//Setters constant
void Sphere::setRadius(const double r)
{
    radius = r;
}

/*void Sphere::setCenter(const Point& p)
 {
 center = p;
 }
 */

void Sphere::setColor(const Color& c)
{
    sphereColor = c;
}

//Getters constant
double Sphere::getRadius() const
{
    return radius;
}

/* Point  Sphere::getCenter() const
 {
 return center;
 }
 */
Color  Sphere::getColor() const
{
    return sphereColor;
}

void Sphere::draw(SDL_Plotter& g) const
{
    for(int newX = -radius; newX <= radius; newX++)
    {
        for(int newY = -radius; newY <= radius; newY++)
        {
            if(sqrt(newX*newX + newY*newY <= radius))
            {
                g.plotPixel(x + newX, y + newY, sphereColor.R, sphereColor.G, sphereColor.B);
                g.plotPixel(x + newX,y - newY, sphereColor.R, sphereColor.G, sphereColor.B);
            }
        }
    }
}

void Sphere::eraseSphere(SDL_Plotter& g) const
{
    for(int newX = -radius; newX <= radius; newX++)
    {
        for(int newY = -radius; newY <= radius; newY++)
        {
            if(sqrt(newX*newX + newY*newY <= radius))
            {
                g.plotPixel(x + newX, y + newY, 255,255,255);
                g.plotPixel(x + newX,y - newY, 255,255,255);
            }
        }
    }
}

/*
 void Sphere::erase(SDL_Plotter& g) const{ //label plotter g
 for(int x = -radius; x <= radius; x++){
 for(int y = -radius; y <= radius;y++){
 if(sqrt(x*x + y*y <= radius)){
 g.plotPixel(x + center.x,y + center.y, 255, 255, 255);
 }
 }
 }
 }
 */

int Sphere::getX()
{
    return x;
}

int Sphere::getY()
{
    return y;
}

void Sphere::setX(int nx)
{
    x = nx;
}

void Sphere::setY(int ny)
{
    y = ny;
}

void Sphere::moveSphere(char direction)
{
    switch (toupper(direction))
    {
            // case 'W':
            //setY(getY() - 5);
            //break;
            // case 'S':
            // setY(getY() + 5);
            // break;
        case 'A':
            if(getX() <= 5)
            {
                setX(getX());
            }
            else
            {
                setX(getX() - 5);
            }
            break;
        case 'D':
            if(getX() >= 695)
            {
                setX(getX());
            }
            else
            {
                setX(getX() + 5);
            }
            break;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** TEXTURE CLASS STUFF **/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SDL_Renderer* renderer = NULL;
SDL_Texture* texture;

class SpaceShipTexture
{
    private:
        int picWidth;
        int picHeight;
        int picX;
        int picY;
    
public:
    int getX();
    void setX(int x);
    void setY(int y);
    int getY();
    int getWidth();
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);
    SDL_Rect setPicLoc(SDL_Rect spriteArray[]);
    bool loadFromFile( std::string path );
    void renderPic(int x, int y, SDL_Rect SpriteArray[] = NULL);
};

int SpaceShipTexture::getX()
{
    return picX;
}

void SpaceShipTexture::setX(int x)
{
    picX = x;
}

void SpaceShipTexture::setY(int y)
{
    picY = y;
}

int SpaceShipTexture::getY()
{
    return picY;
}

int SpaceShipTexture::getHeight()
{
    return picHeight;
}

int SpaceShipTexture::getWidth()
{
    return picWidth;
}

void SpaceShipTexture::setHeight(int h)
{
    picHeight = h;
}

void SpaceShipTexture::setWidth(int w)
{
    picWidth = w;
}

SDL_Rect SpaceShipTexture::setPicLoc(SDL_Rect spriteArray[])
{
    spriteArray[0].x = picX;
    spriteArray[0].y = picY;
    spriteArray[0].h = picHeight;
    spriteArray[0].w = picWidth;
    spriteArray[1].x = picX;
    spriteArray[1].y = picY;
    spriteArray[1].h = picHeight;
    spriteArray[1].w = picWidth;
    spriteArray[2].x = picX;
    spriteArray[2].y = picY;
    spriteArray[2].h = picHeight;
    spriteArray[2].w = picWidth;
    spriteArray[3].x = picX;
    spriteArray[3].y = picY;
    spriteArray[3].h = picHeight;
    spriteArray[3].w = picWidth;
    
    return spriteArray[3];
}

bool loadFromFile( std::string path )
{
    SDL_Texture* newTexture = NULL;
    texture = newTexture;
    return (texture != NULL);
}

void SpaceShipTexture::renderPic(int x, int y, SDL_Rect spriteArray[])
{
    SDL_Rect renderRect = {x, y, picWidth, picHeight};
    SDL_RenderCopy( renderer, texture, &spriteArray[0], &renderRect );
}








#endif // SPHERE_H_INCLUDED
