
#ifndef spaceship_h
#define spaceship_h

#include "Color.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
using namespace std;

//Global Variable for Max Wall Count
const int NUM_WALLS = 1000;

class shipShape
{
private:
    Rectangle ship[NUM_WALLS];
    
public:
    shipShape();
    void draw(SDL_Plotter& g);
    
};

shipShape::shipShape()
{
    //Variable Storage
    double ulx, uly, llx, lly;
    int R, G, B;
    
    //Create file
    ifstream in;
    in.open("spaceship.txt");

    
    //Read
    while(in >> ulx >> uly >> llx >> lly >> R >> G >> B)
    {
        //Rectangle set up
        ship[i].setUpperLeftX(ulx);
        ship[i].setUpperLeftY(uly);
        ship[i].setLowerRightX(llx);
        ship[i].setLowerRightY(lly);
        
        //Color
        ship[i].setColorRectangle(Color(R, G, B));
    }
    
    //Close File
    in.close();
}

void Map::draw(SDL_Plotter& g)
{
    //Data Abstraction to draw the rectangles
    for(int i = 0; i < NUM_WALLS; i++)
    {
        ship[i].drawRectangle(g);
    }
}


#endif /* spaceship_h */
