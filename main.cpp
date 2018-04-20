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
#include "Map.h"

using namespace std;

const int MAX_LEADS = 10;

void setTrue(bool test[], int i);
void setfalse(bool test[], int i);

int main(int argc, char ** argv)
{

    cout << "Created by Code::Masters" << endl;
    cout << "Peter Doe, Carlos Hernandez, Kevin Kulda, and John Patel" << endl;
    cout << "Dr. Fendt (Professor)" << endl;
    cout << "CSI 1430: MWF 11:15 - 12:05" << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Please use the \"w\",\"a\",\"s\" and \"d\" keys to move the" << endl;
    cout << "ship, and the \"g\" key to shoot a laser." << endl;
    cout << "*************************************************" << endl;
    cout << endl;
    cout << "Please Enjoy!" << endl;

    //cout << SDL_GetTicks() << endl;

    //Object Created
    SDL_Plotter g(700, 700);
    Map galagaMap;

    //Variable Storage
    bool stopped = false;
    int x,y;
    //bool moveLaser = false;

    //A default color.
    Color white;
    white.R = 255;
    white.G = 255;
    white.B = 255;

    
    /*
    Sphere ship;

    ship.setX(350);
    ship.setY(600);
    ship.setColor(Color(212, 20, 20));
    ship.setRadius(10);
     */
     
    //RECTANGLE SHIP
    Rectangle falcon;

    falcon.setUpperLeftX(345);
    falcon.setUpperLeftY(595);
    falcon.setLowerRightX(355);
    falcon.setLowerRightY(605);
    falcon.setColorRectangle(Color(20,200,200));

    Rectangle black;
    black.setUpperLeftX(100);
    black.setUpperLeftY(100);   cout << SDL_GetTicks() << endl;
    black.setLowerRightX(600);
    black.setLowerRightY(150);
    black.setColorRectangle(Color(0,0,0));

    /*
     Rectangle top;
     black.setUpperLeftX(1);
     black.setUpperLeftY(1);
     black.setLowerRightX(699);
     black.setLowerRightY(10);
     black.setColorRectangle(Color(255,255,255));
     */

    
    /*
    Rectangle laser;
    laser.setUpperLeftX(345);
    laser.setUpperLeftY(550);
    laser.setLowerRightX(355);
    laser.setLowerRightY(580);
    laser.setColorRectangle(Color(20,200,200));
     */
     
     
    Color test;

    //Projectile Array.
    Rectangle lead[10];
    for(int a = 0; a < MAX_LEADS; a++)
    {
        lead[a].setUpperLeftX(345);
        lead[a].setUpperLeftY(550);
        lead[a].setLowerRightX(355);
        lead[a].setLowerRightY(580);
        lead[a].setColorRectangle(Color(20,200,200));
        lead[a].setFiring(false);
    }
    
    //Enemy Projectile Array.
    Rectangle lazer[15];
    for(int a = 0; a < 10; a++)
    {
        lazer[a].setUpperLeftX(345);
        lazer[a].setUpperLeftY(550);
        lazer[a].setLowerRightX(355);
        lazer[a].setLowerRightY(580);
        lazer[a].setColorRectangle(Color(20,200,200));
        lazer[a].setFiring(false);
    }
    


    //enemy Array.
    Rectangle enemy[10];
    int upperX = 20;
    int upperY = 10;
    int lowerX = 70;
    int lowerY = 60;
    for(int a = 0; a < 10; a++)
    {

        enemy[a].setUpperLeftX(upperX);
        enemy[a].setUpperLeftY(upperY);
        enemy[a].setLowerRightX(lowerX);
        enemy[a].setLowerRightY(lowerY);
        enemy[a].setColorRectangle(Color(255,0,0));
        enemy[a].setSurviving(true);

        upperX += 60;
        lowerX += 60;
    }


    int count = 0;
    char direction1;
    int i;
    bool plotEnemy = true;

    //While the program is running.
    while (!g.getQuit())
    {
        //While the game has not been stopped.
        if(!stopped)
        {
            //Clear the screen.
            g.clear();

            galagaMap.draw(g); //Proper location to draw map
            falcon.drawRectangle(g);  //Redraw the ship

            //When a button is pressed.
            if(g.kbhit())
            {
                // cout << SDL_GetTicks() << endl;

                direction1 = g.getKey();

                switch (toupper(direction1))
                {
                    case 'A': falcon.moveRectangle('A');
                        break;
                    case 'D': falcon.moveRectangle('D');
                        break;
                    case 'G':
                        i = 0;

                        while( i < MAX_LEADS )
                        {
                            if(lead[i].getFiring() == false)
                            {

                                lead[i].setUpperLeftX(falcon.getUpperLeftX());
                                lead[i].setLowerRightX(falcon.getLowerRightX());
                                lead[i].setUpperLeftY(550);
                                lead[i].setLowerRightY(580);
                                lead[i].setFiring(true);
                                i = 10;
                            }
                            i++;
                        }

                        break;
                }

                falcon.moveRectangle(direction1); //Move ship based on key pressed.
                falcon.drawRectangle(g);  //Redraw the ship

            }

            for(int d = 0; d < MAX_LEADS; d++)
            {
                if(lead[d].getFiring() == true)
                {
                    if(lead[d].getUpperLeftY() < 5)
                    {
                        lead[d].setFiring(false);
                        //setfalse(firing, d);
                    }
                    else
                    {
                        lead[d].drawRectangle(g);
                        lead[d].moveLaserUp(g);
                    }
                }
            }
            
            for(int h = 0; h < 10 ; h++)
            {
                if(enemy[h].getSurviving())
                {
                    for(int m = 0; m < 10; m++)
                    {
                        if(lead[m].getFiring())
                        {
                            if(enemy[h].enemyCollision(lead, m))
                            {
                                enemy[h].setSurviving(false);
                                lead[m].setFiring(false);
                            }
                        }
                    }
                }
                
            }

            falcon.drawRectangle(g);

            if(g.kbhit())
            {
                g.getKey();
            }

            int count = 0;
            int tick = 1000;
            
            //XCODE SUGGESTS THIS CHANGE -PETER:
            while(count < 10 && SDL_GetTicks() > tick)
            //while(surviving[10] == true && count < 10 && SDL_GetTicks() > tick)
            {
                if(plotEnemy)
                {
                    //g.Sleep(1000);

                    for(int f = 0; f < 10; f++)
                    {
                        enemy[f].drawRectangle(g);
                        
                        //XCode Suggests this change:
                        //surviving[f] == true;
                        enemy[f].setSurviving(true);
                    }
                    plotEnemy = false;
                }

                if(count % 2 == 0)
                {
                    upperX += 30;
                    upperY -= 30;
                    lowerX += 30;
                    lowerY -= 30;
                }
                else if(count % 2 != 0)
                {
                    upperX -= 30;
                    upperY += 30;
                    lowerX -= 30;
                    lowerY += 30;
                }
                count++;
                tick += 1000;
            }

            for(int f = 0; f < 10; f++)
            {
                if(enemy[f].getSurviving())
                {
                    enemy[f].drawRectangle(g);
                }
            }

            //g.Sleep(10);
            g.update();
        }
        
        if(g.getMouseClick(x,y))
        {
            stopped = !stopped;
        }
    }

    return 0;
}


//We have to move these functions in .h file to minimze deduction on main clutter
void setTrue(bool test[], int i)
{
    test[i] = true;
}

void setfalse(bool test[], int i)
{
    test[i] = false;
}
