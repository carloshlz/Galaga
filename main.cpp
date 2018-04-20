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

const int MID_LINE = 325;

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
    bool moveLaser = false;
    bool start = false;
    int i, j, k, startTime, useTime;
    useTime = 0;
    Point house(35,100);
    
    //A default color.
    Color white;
    white.R = 255;
    white.G = 255;
    white.B = 255;
    
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
    

    
    
    Color test;
    
    //Projectile Array.
    Rectangle lead[10];

    for(int a = 0; a < 10; a++)
    {
        lead[a].setUpperLeftX(345);
        lead[a].setUpperLeftY(550);
        lead[a].setLowerRightX(355);
        lead[a].setLowerRightY(580);
        lead[a].setColorRectangle(Color(20,200,200));
        lead[a].setSurviving(false);
    }
    
    
    //Enemy Projectile Array.
    Rectangle lazer[15];
    /*
    for(int a = 0; a < 10; a++)
    {
        lead[a].setUpperLeftX(345);
        lead[a].setUpperLeftY(550);
        lead[a].setLowerRightX(355);
        lead[a].setLowerRightY(580);
        lead[a].setColorRectangle(Color(20,200,200));
        lead[a].setFiring(false);
    }*/
    
    //enemy Array.
    Rectangle enemy[10];
    int upperX = -100;
    int upperY = -100;
    int lowerX = -100;
    int lowerY = -100;
    
    for(int a = 0; a < 10; a++)
    {
        enemy[a].setUpperLeftX(upperX);
        enemy[a].setUpperLeftY(upperY);
        enemy[a].setLowerRightX(lowerX);
        enemy[a].setLowerRightY(lowerY);
        enemy[a].setColorRectangle(Color(255,0,0));
        enemy[a].setSurviving(false);
        enemy[a].setHome(house);
        house.x += 71;
    }

    j = 0;
    
    int count = 0;
    char direction1;
    bool plotEnemy = true;
    
    //While the program is running.
    while (!g.getQuit())
    {
        
        //While the game has not been stopped.
        if(!stopped)
        {
            //Clear the screen.
            //g.clear();
            
            //galagaMap.draw(g); //Proper location to draw map
            
            falcon.drawRectangle(g);  //Redraw the ship
            falcon.eraseRectangle(g);
            
            
            
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
                        
                        while( i < 10 )
                        {
                            if(lead[i].getSurviving() == false)
                            {
                                
                                lead[i].setUpperLeftX(falcon.getUpperLeftX());
                                lead[i].setLowerRightX(falcon.getLowerRightX());
                                lead[i].setUpperLeftY(550);
                                lead[i].setLowerRightY(580);
                                lead[i].setSurviving(true);
                                i = 10;
                            }
                            i++;
                        }
                        break;
                    case 'S':
                        start = true;
                        cout << "Start" << endl;
                        startTime = SDL_GetTicks();
                        break;
                }
                
                falcon.moveRectangle(direction1); //Move ship based on key pressed.
                falcon.drawRectangle(g);  //Redraw the ship
                falcon.eraseRectangle(g);
                
            }
            
            for(int d = 0; d < 10; d++)
            {
                lead[d].eraseRectangle(g);
                if(lead[d].getSurviving() == true)
                {
                    if(lead[d].getUpperLeftY() < -10)
                    {
                        lead[d].setSurviving(false);
                    }
                    else
                    {
                        lead[d].moveLaserUp(g);
                        lead[d].drawRectangle(g);
                    }
                }
            }
            
            
            
            for(int h = 0; h < 10 ; h++)
            {
                if(lead[h].getSurviving())
                {
                    for(int m = 0; m < 10; m++)
                    {
                        if(lead[m].getSurviving())
                        {
                            if(enemy[h].enemyCollision(lead, m))
                            {
                                enemy[h].setSurviving(false);
                                lead[m].setSurviving(false);
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
            
            /* //WHAT IS THIS SECTION USED FOR??
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
        */
            
            for(int f = 0; f < 10; f++)
            {
                if(enemy[f].getSurviving() == true)
                {
                    enemy[f].drawRectangle(g);
                }
            }
            
            
            
            
            if((start) && (SDL_GetTicks() - startTime >= 1000) && (j < 10))
            {
                startTime += 1000;
                cout << "SPawn" << endl;
                enemy[j].setLowerRightX(30);
                enemy[j].setLowerRightY(130);
                enemy[j].setUpperLeftX(0);
                enemy[j].setUpperLeftY(100);
                enemy[j].setSurviving(true);
                
                j++;
            }
            
            if(SDL_GetTicks() % 50 >= 40 && SDL_GetTicks() <= startTime + 200000 && start)
            {
                for(k = 0; k < 10; k ++)
                {
                    enemy[k].eraseRectangle(g);
                    enemy[k].introMove(g, MID_LINE);
                }
            }
            
            if(SDL_GetTicks() % 50 >= 40 && SDL_GetTicks() + startTime > 20000 && start)
            {
                for(k = 0; k < 10; k ++)
                {
                    enemy[k].eraseRectangle(g);
                    enemy[k].attackMove(g, 1);
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



/*
//We have to move these functions in .h file to minimze deduction on main clutter
void setTrue(bool test[], int i)
{
    test[i] = true;
}

void setfalse(bool test[], int i)
{
    test[i] = false;
}
*/
