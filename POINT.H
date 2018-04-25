/*
 *  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
 *  Assignment Title: Final Project.
 *  Assignment Description: Write your own interpretation of Galaga
 *  Due Date: 4/25/18
 *  Date Created: 04/05/18
 *  Date Last Modified: 4/24/28
 */

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    //Public data types
    int x, y;

/*
Description: default constructor that sets the x and y coordinates of
a point.
Return: none
Precondition: none
Postcondition: x and y points are set to 0
*/
    Point()
    {
        x = y = 0;
    }

/*
Description: default constructor with parameter that sets the x and y
coordinates of a point.
Return: none
Precondition: none
Postcondition: x and y points are set to 0
*/
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

};

#endif // POINT_H_INCLUDED
