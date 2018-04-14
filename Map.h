#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Color.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
using namespace std;

//Global Variable for Max Wall Count
const int NUM_WALLS = 1000;

class Map
{
  private:
    Rectangle map[NUM_WALLS];

  public:
    void Map();
    void draw(SDL_Plotter& g);

};

void Map::Map()
{
    //Variable Storage
    double ulx, uly, llx, lly;
    int R, G, B;

    //Create file
    ifstream inputFile;
    inputFile.open("Map.txt");

    for(int i = 0; i < NUM_WALLS; i++)
    {
        //Read
        inputFile >> ulx >> uly >> llx >> lly >> R >> G >> B;

        //Rectangle set up
        map[i].setUpperLeftX(ulx);
        map[i].setUpperLeftY(uly);
        map[i].setLowerLeftX(llx);
        map[i].setLowerLeftY(lly);

        //Color
        map[i].setColor(Color(R, G, B));
    }

    //Close File
    inputFile.close();
}

void Map::draw(SDL_Plotter& g)
{
    //Data Abstraction to draw the rectangles
    for(int i = 0; i < NUM_WALLS; i++)
    {
        map[i].draw(g);
    }
}

#endif // MAP_H_INCLUDED
