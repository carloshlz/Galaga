#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color
{
    //Public Variables to store color
    int R, G, B;

    //Default Constructor to store Colors
    Color()
    {
        R = G = B = 0;
    }

    //Constructor with the parameters
    Color(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
