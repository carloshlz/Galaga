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
        Sphere(Point centerobject, double r); //Constructor with Point object and radius parameters

        //Setters constant
        void setRadius(const double);
        void setCenter(const Point);
        void setColor(const string);

        //Getters constant
        double getRadius() const;
        Point  getCenter() const;
        Color  getColor() const;

};


#endif // SPHERE_H_INCLUDED
