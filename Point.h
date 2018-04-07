#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
using namespace std;

#include <cmath>
#include <iostream>
using namespace std;

struct Point
{
    //Public data types
    int x, y;

    //default constructor
    Point()
    {
        x = y = 0;
    }

    //Constructor with parameters
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

};

#endif // POINT_H_INCLUDED
