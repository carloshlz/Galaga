/*
* Author: Jon Patel
*Assignment Title: Program 21
* Assignment Description: Follow the program 21's directions.
*                         This assignment tests the ability to
*                         use arrays when classifying a bunch of
*                         sphere data in a file.
* Due Date: 4/04/2018
* Date Created: 3/31/2018
* Date Last Modified: 4/04/2018
*/

/*
* Data Abstraction: Data Abstraction to open file.
*                   Data Abstraction for reading in variables.
* Input: User Input.
*        File Input.
* Output: Output all the data to the screen.
* Process: Process File
*          Process to skip two lines.
*          Process functions of area and volume.
*          Process for Area sum.
*          Process red count.
*          Process counters.
* Assumptions: Assume file has less than 100 sphere data.
*/

#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED
#include <iostream>
#include <cmath>
using namespace std;

//Global Variable
const double PI = 3.14159;

class Sphere
{
    //Private Variables
    private:
        double radius;
        string color;

    public:

//************************************************************
// description: Gets radius     *
// return: Returns radius                  *
// precondition: N/A                          *
// postcondition: N/A                       *
//                                                           *
//************************************************************
        double getRadius();
//************************************************************
// description: Gets color     *
// return: Returns color                 *
// precondition: N/A                          *
// postcondition: N/A                       *
//                                                           *
//************************************************************
        string getColor();
//************************************************************
// description: Set Radius   *
// return: returns radius                 *
// precondition: N/A                          *
// postcondition: N/A                       *
//                                                           *
//************************************************************
        void setRadius(double r);
//************************************************************
// description: Set Color   *
// return: setcolor                   *
// precondition: N/A                          *
// postcondition: N/A                       *
//                                                           *
//************************************************************
        void setColor(string c);
//************************************************************
// description: Default constructor     *
// return: double and string                  *
// precondition: N/A                          *
// postcondition: N/A                       *
//                                                           *
//************************************************************
        Sphere();
//************************************************************
// description: sets radius to r and color to green *
// return: double                                          *
// precondition: radius                           *
// postcondition: N/A                        *
//                                                           *
//************************************************************
        Sphere(double r);
//************************************************************
// description: sets the private data   *
// return: double r and string c             *
// precondition: radius and color                         *
// postcondition: N/A                  *
//                                                           *
//************************************************************
        Sphere(double r, string c);
//************************************************************
// description: Calculates the Surface Area      *
// return: return Surface Area function                     *
// precondition: N/A                             *
// postcondition: gives back a value for SA                   *
//                                                           *
//************************************************************
        double area();
//************************************************************
// description: Calculates the Volume of the Sphere      *
// return: return Volume function                 *
// precondition: N/A                             *
// postcondition: Volume funcitons is returned                  *
//                                                           *
//************************************************************
        double volume();
//************************************************************
// description: Boolean statement that returns true if data are same. *
// return: true or false                                       *
// precondition: needs an object's data                           *
// postcondition: gives back a boolean value                *
//                                                           *
//************************************************************
        bool isEqual(const Sphere&other);
};

#endif // SPHERE_H_INCLUDED
