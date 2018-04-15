/*
*  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
*/

#include <iostream>
#include "SDL_Plotter.h"
#include "Color.h"
#include "Sphere.h"
#include "Point.h"
#include "Rectangle.h"
#include <ctime>

using namespace std;


int main(int argc, char ** argv)
{

    SDL_Plotter g(700, 700);
    bool stopped = false;
    //bool colored = false;
    int x,y;
    int R,G,B;

    Sphere ship;

    ship.setX(350);
    ship.setY(600);
    ship.setColor(Color(212, 20, 20));
    ship.setRadius(10);

    //RECTANGLE SHIP
    Rectangle falcon;

    falcon.setUpperLeftX(345);
    falcon.setUpperLeftY(595);
    falcon.setLowerRightX(355);
    falcon.setLowerRightY(605);
    falcon.setColorRectangle(Color(20,200,200));


    Rectangle black;
    black.setUpperLeftX(1);
    black.setUpperLeftY(1);
    black.setLowerRightX(699);
    black.setLowerRightY(100);
    black.setColorRectangle(Color(0,0,0));


    Rectangle laser;
    laser.setUpperLeftX(345);
    laser.setUpperLeftY(550);
    laser.setLowerRightX(355);
    laser.setLowerRightY(580);
    laser.setColorRectangle(Color(20,200,200));

    Color test;

    cout << "Created by Code::Masters" << endl;
    cout << "Peter Doe, Carlos Hernandez, Kevin Kulda, and John Patel" << endl;
    cout << "Dr. Fendt (Professor)" << endl;
    cout << "CSI 1430: MWF 11:15 - 12:05" << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Please use the \"w\",\"a\",\"s\" and \"d\" keys" << endl;
    cout << "to move the object on the screen." << endl;
    cout << "*************************************************" << endl;
    cout << endl;
    cout << "Please Enjoy!" << endl;


    int count = 0;

    while (!g.getQuit())
    {
        if(!stopped)
        {
            g.clear();

            black.drawRectangle(g);
            ship.draw(g);

            if(black.collision(laser))
            {
              //cout << "Has been hit" << endl;
            }
            else
            {
              laser.drawRectangle(g);
              //g.Sleep(100);
            }


            falcon.drawRectangle(g);

            laser.setUpperLeftY(laser.getUpperLeftY() - 1);
            laser.setLowerRightY(laser.getLowerRightY() - 1);
            //laser.drawRectangle(g);
            g.update();
            //g.Sleep(10);



            char direction1;
            if(g.kbhit())
            {

              direction1 = g.getKey();
                /*
                ship.moveSphere(direction1);
                ship.draw(g);
                */
              falcon.moveRectangle(direction1);
              falcon.drawRectangle(g);
            }
          }

          if(g.kbhit())
          {
            g.getKey();
          }

          if(g.getMouseClick(x,y))
          {
            stopped = !stopped;
          }

          g.update();
    }

    return 0;
}
