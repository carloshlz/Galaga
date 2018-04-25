/*
 *  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
 *  Assignment Title: Final Project.
 *  Assignment Description: Write your own interpretation of Galaga
 *  Due Date: 4/25/18
 *  Date Created: 04/05/18
 *  Date Last Modified: 4/24/28
 */

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

//Struct for colors
struct Color
{
    //Public Variables to store color
    int R, G, B;

/*
Description: default constructor that sets the a color.
Return: none
Precondition: none
Postcondition: RGB values are set to 0
*/
    Color()
    {
        R = G = B = 0;
    }

/*
Description: default constructor with parameters that sets the a color.
Return: none
Precondition: none
Postcondition: RGB values are set to parameter values.
*/
    Color(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
