/*
 *  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
 *  Assignment Title: Final Project.
 *  Assignment Description: Write your own interpretation of Galaga
 *  Due Date: 4/25/18
 *  Date Created:
 *  Date Last Modified: 4/24/28
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

//Initializing constants
const int MID_LINE = 525;
const int NUMBER_OF_FRIENDLY_LASERS = 2;
const int NUMBER_OF_ENEMY_LASERS = 10;
const int INTRO_END_TIME = 12000;
const int LEFT_RIGHT_START_TIME = 12000;
const int ATTACK_START_TIME = 18000;
const int SPAWN_DELAY = 600;
const int BATTLE_LOCATION_ENEMY_INCREMENT = 70;
const int NUMBER_OF_ENEMIES_EASY = 10;

int main(int argc, char ** argv)
{
    //Message printed to the screen
    
    cout << "Created by Code::Masters" << endl;
    cout << "Peter Doe, Carlos Hernandez, Kevin Kulda, and John Patel" << endl;
    cout << "Dr. Fendt (Professor)" << endl;
    cout << "CSI 1430: MWF 11:15 - 12:05" << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Please use the \"a\" and \"d\" keys to move the" << endl;
    cout << "ship, and the \"s\" key to shoot a laser." << endl;
    cout << "Press the \"f\" key to start the game, and click" << endl;
    cout << "with the mouse to pause the game." << endl;
    cout << "*************************************************" << endl;
    cout << endl;
    cout << "Please Enjoy!" << endl;
    
    //cout << SDL_GetTicks() << endl;
    
    //For output to the sceen
    SDL_Plotter g(1000, 1000);
    
    //For the map
    Map galagaMap;
    
    //Variable Storage
    bool stopped = false; //Records a game pause
    bool start = false; //Records the game beginning
    int mouseClick1,mouseClick2; //Records whether the mouse was clicked
    int howManyAreSpawned; //Records the number of
                            //enemies that have spawned for the current round
    int i, j; //Counter variables
    howManyAreSpawned = 0;
    
    //Variables to record the time when certain events happen
    double startTime, useTime, attackTime;
    startTime = 0;
    useTime = 0;
    attackTime = 0;
    
    //The first resting point of the enemis
    Point house(95,100);
    
    //Booleans for the movement functions
    bool moveTheEnemyRight = true;
    bool moveTheEnemyLeft = false;
    
    //The character for the movement function
    char direction1;
    
    //A default color.
    Color white;
    white.R = 255;
    white.G = 255;
    white.B = 255;
    
    //COLOR ARRAY:
    int red[10];
    int green[10];
    int blue[10];
    
    //Setting the values of the color array:
    red[0] = 255;
    red[1] = 255;
    red[2] = 0;
    red[3] = 0;
    red[4] = 0;
    red[5] = 200;
    red[6] = 150;
    red[7] = 255;
    red[8] = 150;
    red[9] = 200;
    
    green[0] = 0;
    green[1] = 255;
    green[2] = 255;
    green[3] = 255;
    green[4] = 0;
    green[5] = 100;
    green[6] = 150;
    green[7] = 150;
    green[8] = 255;
    green[9] = 150;
    
    blue[0] = 0;
    blue[1] = 0;
    blue[2] = 0;
    blue[3] = 255;
    blue[4] = 255;
    blue[5] = 180;
    blue[6] = 255;
    blue[7] = 150;
    blue[8] = 150;
    blue[9] = 150;
    
    //Initializing the player's ship
    Rectangle falcon;
    
    //Setting the player location
    falcon.setUpperLeftX(490);
    falcon.setUpperLeftY(600);
    falcon.setLowerRightX(525);
    falcon.setLowerRightY(640);
    falcon.setColorRectangle(Color(20,200,200));
    
    Rectangle casket;
    casket.setUpperLeftX(20);
    casket.setUpperLeftY(680);
    casket.setLowerRightX(30);
    casket.setLowerRightY(690);
    casket.setColorRectangle(Color(0,200,0));
    casket.setSurviving(false);
    
    //Initializing the friendly projectile array
    Rectangle lead[NUMBER_OF_FRIENDLY_LASERS];

    //Setting the colors for the friendly projectiles
    for(i = 0; i < NUMBER_OF_FRIENDLY_LASERS; i++)
    {
        //I don't think that we need to set these locations
        //but the might be necessary if the program tries to draw them
        //off screen
        /*
        lead[i].setUpperLeftX(345);
        lead[i].setUpperLeftY(550);
        lead[i].setLowerRightX(355);
        lead[i].setLowerRightY(580);
         */
        lead[i].setColorRectangle(Color(255,20,250));
        lead[i].setSurviving(false);
    }
    
    
    //Initializing the enemy projectile array
    Rectangle lazer[NUMBER_OF_ENEMY_LASERS];
    
    //Setting the colors for the enemy projectiles
    for(i = 0; i < NUMBER_OF_ENEMY_LASERS; i++)
    {
        //Same as above
        /*
        lazer[i].setUpperLeftX(345);
        lazer[i].setUpperLeftY(550);
        lazer[i].setLowerRightX(355);
        lazer[i].setLowerRightY(580);
         */
        lazer[i].setColorRectangle(Color(red[i],green[i], blue[i]));
        lazer[i].setSurviving(false);
    }
    
    //Initializing an array of enemies
    Rectangle enemy[NUMBER_OF_ENEMIES_EASY];
    
    
    //While the program is running.
    while (!g.getQuit())
    {
        //While the game has not been stopped.
        if(!stopped)
        {
            
            //Clear the screen.
            //g.clear();

            galagaMap.draw(g);  //Draw the map
            //falcon.drawRectangle(g);  //Not needed
            falcon.eraseRectangle(g);
            
            
            //When a button is pressed.
            if(g.kbhit())
            {
                direction1 = g.getKey(); //Set the direction to the input
                switch (toupper(direction1))
                {
                    case 'A': falcon.moveRectangle('A');//Move the ship left
                        break;
                    case 'D': falcon.moveRectangle('D');//Move the ship right
                        break;
                    case 'S':
                        i = 0;
                        while( i < NUMBER_OF_FRIENDLY_LASERS )//Check every friendly project
                        {
                            if(lead[i].getSurviving() == false) //If it is not active
                            {
                                //Initialized it
                                lead[i].setUpperLeftX(falcon.getUpperLeftX() + 15);
                                lead[i].setLowerRightX(falcon.getLowerRightX() - 15);
                                lead[i].setUpperLeftY(569);
                                lead[i].setLowerRightY(599);
                                lead[i].setSurviving(true);
                                i = NUMBER_OF_FRIENDLY_LASERS;//Stop the loop if a projectile is fired
                            }
                            i++;//else, check the next projectile
                        }
                        break;
                    case 'R':
                        //Start the game
                        start = true;
                        startTime = SDL_GetTicks(); //Record the starting time
                        useTime = startTime; //Set the useTime to this as well
                        howManyAreSpawned = 0; //Reset the number of enemies spawned
                        
                        //For every enemy:
                        for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
                        {
                            enemy[i].eraseRectangle(g); //Erase it
                            enemy[i].setColorRectangle(Color(red[i], green[i], blue[i])); //Reset it's color
                            enemy[i].setSurviving(false); //Kill it
                            enemy[i].setHome(house); //Reset it's home
                            house.x += BATTLE_LOCATION_ENEMY_INCREMENT; //Add to the home increment, so that
                                                                        //the enemies will have different homes
                        }
                        break;
                }
            }
            
            //Updating the friendly projectiles ***********
            //For every friendly projectile:
            for(i = 0; i < NUMBER_OF_FRIENDLY_LASERS; i++)
            {
                lead[i].eraseRectangle(g); //Erase it
                if(lead[i].getSurviving()) //If it is still alive
                {
                    //If it is off the screen
                    if(lead[i].getUpperLeftY() < 10)
                    {
                        lead[i].setSurviving(false); //Kill it
                    }
                    else
                    {
                        lead[i].moveLaserUp(g); //Move it up
                        lead[i].drawRectangle(g); //Draw it
                    }
                }
            }

            //Checking for collision with the enemy:
            //For every enemy;
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY ; i++)
            {
                //If the enemy is still alive:
                if(enemy[i].getSurviving())
                {
                    //For each of our projectiles:
                    for(j = 0; j < NUMBER_OF_FRIENDLY_LASERS; j++)
                    {
                        //If the projectile is still alive:
                        if(lead[j].getSurviving())
                        {
                            //Check for a collision
                            if(enemy[i].enemyCollision(lead, j))
                            {
                                // If so:
                                enemy[i].setSurviving(false); //Kill the enemy
                                enemy[i].eraseRectangle(g); //Erase the enemy
                                
                                //Probably not needed
                                /*
                                enemy[i].setUpperLeftX(395); //Reset their location
                                enemy[i].setUpperLeftY(390);
                                enemy[i].setLowerRightX(390);
                                enemy[i].setLowerRightY(395);
                                */
                                
                                lead[j].setSurviving(false);//Kill the projectile
                                lead[j].eraseRectangle(g); //Erase the projectile
                            }
                        }
                    }
                }
            }
            
            if(casket.getSurviving())
            {
                casket.drawRectangle(g);
            }
            
            //Draw the player ship
            falcon.drawRectangle(g);
            
            //Record the input key
            if(g.kbhit())
            {
                g.getKey();
            }
            
            //For every enemy:
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
            {
                //If the enemy is alive:
                if(enemy[i].getSurviving() == true)
                {
                    enemy[i].drawRectangle(g); //Draw it
                }
            }
            
            
            //Spawning the enemies ***************
            //If the game has started, there has elapsed at least the spawn delay constant,
            //and no more than the designated number enemies have been spawned:
            if((start) && (SDL_GetTicks() - useTime >= SPAWN_DELAY) && howManyAreSpawned < NUMBER_OF_ENEMIES_EASY)
            {
                //reset the time elapsed
                useTime += SPAWN_DELAY;
                
                //Spawn the enemies at this location
                enemy[howManyAreSpawned].setLowerRightX(140);
                enemy[howManyAreSpawned].setLowerRightY(130);
                enemy[howManyAreSpawned].setUpperLeftX(110);
                enemy[howManyAreSpawned].setUpperLeftY(100);
                
                //Record that they are now active
                enemy[howManyAreSpawned].setSurviving(true);
                
                //Update the number of spawned enemies
                howManyAreSpawned++;
            }

            //Intro moves *************
            //At random (but fairly consistent intervals), if the current time is less
            //than the time that the game started at plus the intro time constant, and
            //the game has started:
            if(SDL_GetTicks() % 50 >= 40 && SDL_GetTicks() <= startTime + INTRO_END_TIME && start)
            {
                //For every enemy
                for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i ++)
                {
                    //If it is alive;
                    if(enemy[i].getSurviving())
                    {
                        //Erase, use the intro move function, and then draw it
                        enemy[i].eraseRectangle(g);
                        enemy[i].introMove(g, MID_LINE);
                        enemy[i].drawRectangle(g);
                    }
                }
            }
            
            //Moving enemies left and right *************
            //At random (but fairly consistent intervals), if moveTheEnemyRight is
            //true, and the time is correct, and the game has started:
            if(SDL_GetTicks() % 50 >= 40
               && moveTheEnemyRight
               && SDL_GetTicks() >= startTime + LEFT_RIGHT_START_TIME
               && start
               )
            {
                //For every enemy
                for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
                {
                    //If it is alive:
                    if(enemy[i].getSurviving())
                    {
                        enemy[i].eraseRectangle(g); //Erase it
                        enemy[i].moveEnemyRight(); //Move it
                        enemy[i].drawRectangle(g); //Draw it
                        //If it is too far right
                        if(enemy[i].getLowerRightX() > 940)
                        {
                            //Make all the enemies move left next time
                            moveTheEnemyRight = false;
                            moveTheEnemyLeft = true;
                        }
                        
                    }
                }
            }
            
            //At random (but fairly consistent intervals), if moveTheEnemyRight is
            //true, and the time is correct, and the game has started:
            if(moveTheEnemyLeft == true
                    && SDL_GetTicks() % 50 >= 40
                    &&   SDL_GetTicks() >= startTime + LEFT_RIGHT_START_TIME
                    && start
               )
            {
                //For every enemy
                for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
                {
                    //If it is alive:
                    if(enemy[i].getSurviving())
                    {
                        enemy[i].eraseRectangle(g); //Erase it
                        enemy[i].moveEnemyLeft(); //Move it
                        enemy[i].drawRectangle(g); //Draw it
                        if(enemy[i].getUpperLeftX() < 50) //If it is too far left:
                        {
                            //Make all the enemies move right next time
                            moveTheEnemyRight = true;
                            moveTheEnemyLeft = false;
                        }
                    }
                }
            }

            
            
            //Attack moves:
            /*
             This section uses slightly different logic, since it must record
             how many ships have moved before each ship to see whether it should
             do the attack move.
            */
            
            //For every enemy:
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
            {
                /*
                 If:
                    1) The enemy is alive,
                    2) At a random (but fairly consistent interval),
                    3) The proper time in the game has been reached,
                    4) The game has started, and
                    5) Two seconds have elapsed since the previous ship began
                        its attack move:
                 */
                if((enemy[i].getSurviving())
                   && SDL_GetTicks() % 50 >= 40
                   && SDL_GetTicks() - startTime > ATTACK_START_TIME
                   && start
                   && SDL_GetTicks() - startTime - ATTACK_START_TIME  >= 2000 * i)
                    {
                        enemy[i].eraseRectangle(g); //Erase it
                        if(moveTheEnemyLeft) //If the enemies are moving left
                        {
                            enemy[i].moveEnemyLeft(); //Move an extra two times
                            enemy[i].moveEnemyLeft();
                        }
                        else
                        {
                            enemy[i].moveEnemyRight(); //Move an extra two times
                            enemy[i].moveEnemyRight();
                        }
                        enemy[i].attackMove(g); //Perform the attack move
                        enemy[i].drawRectangle(g); //And draw the enemy
                    }
            }
            
        
            
            //Enemy fire control
            if(SDL_GetTicks() % 300 >= 295)
            {
                i = SDL_GetTicks() % 37;
                i = i % 10;
                if(enemy[i].getSurviving())
                    for(j = 0; j < NUMBER_OF_ENEMY_LASERS; j++)
                    {
                        if (!lazer[j].getSurviving())
                        {
                            lazer[j].setSurviving(true);
                            lazer[j].setUpperLeftX(enemy[i].getUpperLeftX() + 10);
                            lazer[j].setLowerRightX(enemy[i].getLowerRightX() - 10);
                            lazer[j].setUpperLeftY(enemy[i].getUpperLeftY() + 30);
                            lazer[j].setLowerRightY(enemy[i].getLowerRightY() + 35);
                            j = 10;
                        }
                    }
                i ++;
            }
            
             
            
            //Updating the enemy's lasers
            for(i = 0; i < NUMBER_OF_ENEMY_LASERS; i++)
            {
                if(lazer[i].getSurviving() == true)
                {
                    if(lazer[i].getUpperLeftY() > 900)
                    {
                        lazer[i].setSurviving(false);
                        lazer[i].eraseRectangle(g);
                    }
                    else
                    {
                        lazer[i].eraseRectangle(g);
                        lazer[i].moveLaserDown(g);
                        lazer[i].drawRectangle(g);
                    }
                }
            }
            
            for(i = 0; i < NUMBER_OF_ENEMY_LASERS; i++)
            {
                if(lazer[i].getSurviving() == true)
                {
                    if(falcon.shipCollision(lazer, i))
                    {
                        lazer[i].setSurviving(false);
                        //falcon.setSurviving(false);
                        cout << "HIT" << endl;
                    }
                }
            }
            
            //Killing offscreen enemies:
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
            {
                if((enemy[i].getLowerRightX() >= 990
                   || enemy[i].getLowerRightX() <= 40
                   || enemy[i].getLowerRightY() >= 900
                   || enemy[i].getLowerRightY() <= 40)
                   && enemy[i].getSurviving()
                   )
                {
                    enemy[i].eraseRectangle(g);
                    enemy[i].setSurviving(false);
                }
            }
            
            
            //g.Sleep(100);
            g.update();
            
        }
        
        if(g.getMouseClick(mouseClick1,mouseClick2))
        {
            stopped = !stopped;
        }
        
        
        
    }
    
    return 0;
}

