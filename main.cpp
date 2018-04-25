/*
 *  Authors: Peter Doe, Carlos Hernandez, Kevin Kulda, and Jon Patel.
 *  Assignment Title: Final Project.
 *  Assignment Description: Write your own interpretation of Galaga
 *  Due Date: 4/25/18
 *  Date Created: 04/05/18
 *  Date Last Modified: 4/24/28
 */

 /*
 *  Input: User input through key input. User input through click.
 *  Process: A rectangle array for the the player's ship:
 *           Filling in the locations of the rectangles that compose the ship
 *           Initializing the player's ship
 *           Initializing the friendly projectile array
 *           Filling in the locations of the rectangles that compose the ship
 *           Read in data for a text file.
 *           Process movement for aliens.
 *           Process movement for ship's rectangles from files
 *  Output: Output all the data to the screen.
 *  Data Abstraction: Data Abstraction to get game running.
 *                    Data Abstraction to get aliens moving
 *                    Data Abstraction to get sound working.
 *                    Data Abstraction to get user input from key
 *                    Data Abstraction to set the lives of live count
 *                    Data Abstraction to end the game loop
 *                    Data Abstraction for counters for reading the loops
 *                    Data Abstraction to attack aliens.
 *                    Data Abstraction in other areas to finalize the game.
 *  Assumptions: Assume user knows controls to the game.
 *               Assume user doesn't want to track hit count.
 *               Assume user knows this is first iteration of game
 *               Assume user knows this is a reflex exercise.
 */
#include <iostream>
#include "SDL_Plotter.h"
#include "Color.h"
#include "Point.h"
#include "Rectangle.h"
#include <ctime>
#include "MAP.H"

using namespace std;

//Initializing constants
const int MID_LINE = 500;
const int NUMBER_OF_FRIENDLY_LASERS = 2;
const int NUMBER_OF_ENEMY_LASERS = 10;
const int INTRO_END_TIME = 12000;
const int LEFT_RIGHT_START_TIME = 12000;
const int ATTACK_START_TIME = 18000;
const int SPAWN_DELAY = 600;
const int BATTLE_LOCATION_ENEMY_INCREMENT = 80;
const int NUMBER_OF_ENEMIES_EASY = 10;
const int MAX = 11;

int main(int argc, char ** argv)
{
    string sound1 = "CollisionSound.wav";
    string sound2 = "laser.wav";

    //Message printed to the screen
    cout << "Created by Code::Masters" << endl;
    cout << "Peter Doe, Carlos Hernandez, Kevin Kulda, and John Patel" << endl;
    cout << "Dr. Fendt (Professor)" << endl;
    cout << "CSI 1430: MWF 11:15 - 12:05" << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Please use the \"a\" and \"d\" keys to move the" << endl;
    cout << "ship, and the \"s\" key to shoot a laser." << endl;
    cout << "Press the \"r\" key to start the game, and click" << endl;
    cout << "with the mouse to pause and resume the game." << endl;
    cout << "*************************************************" << endl;
    cout << endl;
    cout << "Please Enjoy!" << endl;

    //For output to the screen
    SDL_Plotter g(1001, 1001);

    //A rectangle array for the the player's ship:
    Rectangle ship[MAX];
    int shipCount = 0;
    ifstream in;
    in.open("spaceship.txt");

    //Filling in the locations of the rectangles that compose the ship
    int upperx, uppery, lowerx, lowery, rd, gn, be;
    while(in >> upperx >> uppery >> lowerx >> lowery >> rd >> gn >> be )
    {
        ship[shipCount].setUpperLeftX(upperx);
        ship[shipCount].setUpperLeftY(uppery);
        ship[shipCount].setLowerRightX(lowerx);
        ship[shipCount].setLowerRightY(lowery);
        ship[shipCount].setColorRectangle(Color(rd, gn, be));
        shipCount++;
    }

    //Preparing sounds
    g.initSound(sound1);
    g.initSound(sound2);

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
    bool drawonce = true;

    //Variables to record the time when certain events happen
    double startTime, useTime;
    startTime = 0;
    useTime = 0;

    //The first resting point of the enemies
    Point house(105,140);

    //Booleans for the movement functions
    bool moveTheEnemyRight = true;
    bool moveTheEnemyLeft = false;

    //The character for the movement function
    char direction1;

    //Color for life counter
    Color red1;
    red1.R = 255;
    red1.G = 0;
    red1.B = 0;

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
    falcon.setUpperLeftX(510);
    falcon.setUpperLeftY(860);
    falcon.setLowerRightX(600);
    falcon.setLowerRightY(870);
    falcon.setColorRectangle(Color(20,200,200));
    falcon.setLives(3);


    //Initializing the friendly projectile array
    Rectangle lead[NUMBER_OF_FRIENDLY_LASERS];

    //Setting the colors for the friendly projectiles
    for(i = 0; i < NUMBER_OF_FRIENDLY_LASERS; i++)
    {

        lead[i].setColorRectangle(Color(255,20,250));
        lead[i].setSurviving(false);
    }


    //Initializing the enemy projectile array
    Rectangle lazer[NUMBER_OF_ENEMY_LASERS];

    //Setting the colors for the enemy projectiles
    for(i = 0; i < NUMBER_OF_ENEMY_LASERS; i++)
    {

        lazer[i].setColorRectangle(Color(red[i],green[i], blue[i]));
        lazer[i].setSurviving(false);
    }

    //Initializing an array of enemies
    Rectangle enemy[NUMBER_OF_ENEMIES_EASY];

    //To display the number of lives
    Rectangle fakeFalcon1;
    Rectangle fakeFalcon2;

    //While the program is running.
    while (!g.getQuit())
    {
        //While the game has not been stopped.
        if(!stopped)
        {

            //Just once:
            if(drawonce)
            {
                galagaMap.draw(g);  //Draw the map
                drawonce = false;
            }

            //falcon.drawRectangle(g);  //Not needed
            falcon.eraseRectangle(g);
            //Data Abstraction to draw the ship
            for(int i = 0; i < MAX; i++)
            {
                ship[i].drawRectangle(g);
            }


            //When a button is pressed.
            if(g.kbhit())
            {
                direction1 = g.getKey(); //Set the direction to the input
                switch (toupper(direction1))
                {
                    case 'A':
                    {
                      if(ship[4].getUpperLeftX() <= 70)
                      {

                      }
                      else
                      {
                        //Erase all of the ship's rectangles
                        for(int i = 0; i < MAX; i++)
                        {
                            ship[i].eraseRectangle(g);
                        }
                        //Move all of the ship's rectangles
                        for(int i = 0; i < MAX; i++)
                        {
                            ship[i].moveRectangle('A');
                        }
                        falcon.moveRectangle('A');//Move the ship left
                      }
                        break;
                    }
                    case 'D':
                    {
                      if(ship[5].getLowerRightX() > 930)
                      {

                      }
                      else
                      {
                        //Erase all of the ship's rectangles
                        for(int i = 0; i < MAX; i++)
                        {
                            ship[i].eraseRectangle(g);
                        }
                        //Move all of the ship's rectangles
                        for(int i = 0; i < MAX; i++)
                        {
                            ship[i].moveRectangle('D');
                        }
                        falcon.moveRectangle('D');//Move the ship right
                      }
                        break;
                    }
                    case 'S':

                        i = 0;
                        while( i < NUMBER_OF_FRIENDLY_LASERS )//Check every friendly project
                        {
                            if(lead[i].getSurviving() == false) //If it is not active
                            {
                                //Initialized it
                                lead[i].setUpperLeftX(falcon.getUpperLeftX() + 40);
                                lead[i].setLowerRightX(falcon.getLowerRightX() - 40);
                                lead[i].setUpperLeftY(790);
                                lead[i].setLowerRightY(810);
                                lead[i].setSurviving(true);
                                i = NUMBER_OF_FRIENDLY_LASERS;//Stop the loop if a projectile is fired

                                //Play the projectile sound.
                                g.playSound(sound2);
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
                        falcon.setLives(3);

                        //Print the life counters to teh screen
                        fakeFalcon1.setUpperLeftX(445);
                        fakeFalcon1.setUpperLeftY(930);
                        fakeFalcon1.setLowerRightX(475);
                        fakeFalcon1.setLowerRightY(960);
                        fakeFalcon1.setColorRectangle(red1);
                        fakeFalcon1.drawRectangle(g);

                        fakeFalcon2.setUpperLeftX(505);
                        fakeFalcon2.setUpperLeftY(930);
                        fakeFalcon2.setLowerRightX(535);
                        fakeFalcon2.setLowerRightY(960);
                        fakeFalcon2.setColorRectangle(red1);
                        fakeFalcon2.drawRectangle(g);

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
                    if(lead[i].getUpperLeftY() < 105)
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
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
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

                                lead[j].setSurviving(false);//Kill the projectile
                                lead[j].eraseRectangle(g); //Erase the projectile

                                //Play the collision sound.
                                g.playSound(sound1);
                            }
                        }
                    }
                }
            }

            falcon.setSurviving(true);
            //Draw the player ship
            if(falcon.getSurviving())
            {
                falcon.drawRectangle(g);
            }


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
                enemy[howManyAreSpawned].setLowerRightY(180);
                enemy[howManyAreSpawned].setUpperLeftX(110);
                enemy[howManyAreSpawned].setUpperLeftY(150);

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
                        if(enemy[i].getLowerRightX() > 930)
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
                        if(enemy[i].getUpperLeftX() < 100) //If it is too far left:
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
            //At a random interval
            if(SDL_GetTicks() % 300 >= 295)
            {
                //Esssentially generate a random number
                i = SDL_GetTicks() % 37;
                //Size it down to the proper size
                i = i % 10;
                //If the corresponding enemy is still alive
                if(enemy[i].getSurviving())
                    //Check through all of the enemy projectiles
                    for(j = 0; j < NUMBER_OF_ENEMY_LASERS; j++)
                    {
                        //Find one that is not active
                        if (!lazer[j].getSurviving())
                        {
                            //Make it active, and spawn it at the appropriate enemy
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
                //If the laser is still active:
                if(lazer[i].getSurviving())
                {
                    //If it is out of bounds:
                    if(lazer[i].getUpperLeftY() > 860)
                    {
                        lazer[i].setSurviving(false);
                        lazer[i].eraseRectangle(g);
                    }
                    else
                    //Otherwise, move it and draw it
                    {
                        lazer[i].eraseRectangle(g);
                        lazer[i].moveLaserDown(g);
                        lazer[i].drawRectangle(g);
                    }
                }
            }

            //Detect if a lazer has hit the ship
            //For every enemy lazer:
            for(i = 0; i < NUMBER_OF_ENEMY_LASERS; i++)
            {
                //If it is still alive
                if(lazer[i].getSurviving())
                {
                    //If it collides with the player ship
                    if(falcon.shipCollision(lazer, i))
                    {
                        //Play the collision sound.
                        g.playSound(sound1);

                        //Kill and erase the laser
                        lazer[i].setSurviving(false);
                        lazer[i].eraseRectangle(g);

                        //Remove a life from the player
                        falcon.setLives(falcon.getLives() - 1);

                        //Erase the appropriate life counter
                        if(falcon.getLives() == 2)
                        {
                            fakeFalcon1.eraseRectangle(g);
                        }
                        else if(falcon.getLives() == 1)
                        {
                            fakeFalcon2.eraseRectangle(g);
                        }
                        else if(falcon.getLives() == 0)
                        {
                            //If the player is dead, then erase all of the enemies
                            falcon.setSurviving(false);
                            for(j = 0; j < NUMBER_OF_ENEMIES_EASY; j ++)
                            {
                                enemy[j].setSurviving(false);
                            }
                        }
                    }
                }
            }

            //Detect if an enemy has hit the ship.
            //For every enemy:
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
            {
                //Check if the enemy is still alive
                if(enemy[i].getSurviving())
                {
                    //If the player ship collides with the enemy
                    if(falcon.shipCollision(enemy, i))
                    {
                        //Play the collision sound.
                        g.playSound(sound1);

                        //Kill the enemy
                        enemy[i].setSurviving(false);
                        enemy[i].eraseRectangle(g); //Erase it

                        //Remove a player ship life
                        falcon.setLives(falcon.getLives() - 1);

                        //Erase the appropriate life counter
                        if(falcon.getLives() == 2)
                        {
                            fakeFalcon1.eraseRectangle(g);
                        }
                        else if(falcon.getLives() == 1)
                        {
                            fakeFalcon2.eraseRectangle(g);
                        }
                        else if(falcon.getLives() == 0)
                        {
                            //If the player is dead, then erase all of the enemies
                            falcon.setSurviving(false);
                            for(j = 0; j < NUMBER_OF_ENEMIES_EASY; j ++)
                            {
                                enemy[j].setSurviving(false);
                            }
                        }
                    }
                }
            }

            //Killing offscreen enemies:
            //For every enemy
            for(i = 0; i < NUMBER_OF_ENEMIES_EASY; i++)
            {
                //If it is outside of any bound
                if((enemy[i].getLowerRightX() >= 990
                    || enemy[i].getLowerRightX() <= 40
                    || enemy[i].getLowerRightY() >= 870
                    || enemy[i].getLowerRightY() <= 40)
                   && enemy[i].getSurviving()
                   )
                    //Then erase it, and kill it
                {
                    enemy[i].eraseRectangle(g);
                    enemy[i].setSurviving(false);
                }
            }
            g.update();
        }
        //If the mouse is clicked, change the pause state
        if(g.getMouseClick(mouseClick1,mouseClick2))
        {
            stopped = !stopped;
        }
    }

    return 0;
}

