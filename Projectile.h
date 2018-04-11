#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED


#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include <iostream>

using namespace std;

//Global Variable
const double PI = 3.14159;

class Projectile
{
    private:
        double radius;
        //Point center;
        Color projectileColor;

        int x, y;


    public:
        Projectile();  //Default constructor
        Projectile(Point centerObject, double r); //Constructor with Point object and radius parameters

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
        void eraseProjectile(SDL_Plotter& g) const;

        void moveProjectile(); //(char direction);

};

        Projectile::Projectile()  //Default constructor
        {
          x = 300;
          y = 650;
          radius = 10;
          projectileColor = Color(220, 20, 20);
        }

        Projectile::Projectile(Point centerObject, double r) //Constructor with Point object and radius parameters
        {
          x = 300;
          y = 650;
          r = 10;
          projectileColor = Color(220, 20, 20);
        }

        //Setters constant
        void Projectile::setRadius(const double r)
        {
          radius = r;
        }

        /*void Sphere::setCenter(const Point& p)
        {
          center = p;
        }
        */

        void Projectile::setColor(const Color& c)
        {
          projectileColor = c;
        }

        //Getters constant
        double Projectile::getRadius() const
        {
          return radius;
        }

       /* Point  Sphere::getCenter() const
        {
          return center;
        }
*/
        Color  Projectile::getColor() const
        {
          return projectileColor;
        }

void Projectile::draw(SDL_Plotter& g) const
{
  for(int newX = -radius; newX <= radius; newX++)
    {
      for(int newY = -radius; newY <= radius; newY++)
      {
          if(sqrt(newX*newX + newY*newY <= radius))
          {
            g.plotPixel(x + newX, y + newY, projectileColor.R, projectileColor.G, projectileColor.B);
            g.plotPixel(x + newX,y - newY, projectileColor.R, projectileColor.G, projectileColor.B);
          }
      }
    }
}

void Projectile::eraseProjectile(SDL_Plotter& g) const
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

int Projectile::getX()
{
  return x;
}

int Projectile::getY()
{
  return y;
}

void Projectile::setX(int nx)
{
  x = nx;
}

void Projectile::setY(int ny)
{
  y = ny;
}

void Projectile::moveProjectile()
{

    setY(getY() - 5);

  /*
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
            */
}

#endif // PROJECTILE_H_INCLUDED
