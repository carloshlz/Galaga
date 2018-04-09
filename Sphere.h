#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include <iostream>

using namespace std;

//Global Variable
const double PI = 3.14159;

class Sphere
{
    private:
        double radius;
        Point center;
        Color sphereColor;

    public:
        Sphere();  //Default constructor
        Sphere(Point centerObject, double r); //Constructor with Point object and radius parameters

        //Setters constant
        void setRadius(const double);
        void setCenter(const Point&);
        void setColor(const Color&);

        //Getters constant
        double getRadius() const;
        Point  getCenter() const;
        Color  getColor() const;

        void draw(SDL_Plotter&) const;
        void erase(SDL_Plotter&) const;

        //void moveSphere(char direction);

};

        Sphere::Sphere()  //Default constructor
        {
          center = Point(350, 600);
          radius = 10;
          sphereColor = Color(220, 20, 20);
        }

        Sphere::Sphere(Point centerObject, double r) //Constructor with Point object and radius parameters
        {
          center = Point(350, 600);
          r = 10;
          sphereColor = Color(220, 20, 20);
        }

        //Setters constant
        void Sphere::setRadius(const double r)
        {
          radius = r;
        }

        void Sphere::setCenter(const Point& p)
        {
          center = p;
        }

        void Sphere::setColor(const Color& c)
        {
          sphereColor = c;
        }

        //Getters constant
        double Sphere::getRadius() const
        {
          return radius;
        }

        Point  Sphere::getCenter() const
        {
          return center;
        }

        Color  Sphere::getColor() const
        {
          return sphereColor;
        }

        void Sphere::draw(SDL_Plotter& g) const{ //label plotter g
    for(int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius;y++){
            if(sqrt(x*x + y*y <= radius)){
            g.plotPixel(x + center.x,y + center.y, sphereColor.R, sphereColor.G, sphereColor.B);
            g.plotPixel(x + center.x,-y + center.y, sphereColor.R, sphereColor.G, sphereColor.B);
            }
        }
    }
}

void Sphere::erase(SDL_Plotter& g) const{ //label plotter g
    for(int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius;y++){
            if(sqrt(x*x + y*y <= radius)){
            g.plotPixel(x + center.x,y + center.y, 255, 255, 255);
            }
        }
    }
}
/*
void PlayerShip::moveShip(char direction)
{
    switch (direction)
    {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
    }
}
*/




#endif // SPHERE_H_INCLUDED
