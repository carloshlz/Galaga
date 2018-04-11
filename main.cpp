

#include <iostream>

#include "SDL_Plotter.h"
#include "Color.h"
#include "Sphere.h"
#include "Point.h"
#include "Rectangle.h"
#include "Projectile.h"
#include <ctime>



using namespace std;


/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/
/*
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0,0,0)); //0xFF, 0xFF, 0xFF ) );

			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds
			//SDL_Delay( 2000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
*/

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

    Projectile missile;

    missile.setX(350);
    missile.setY(595);
    missile.setColor(Color(212, 20, 20));
    missile.setRadius(10);

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
      //cout << time << endl;
     // count++;

			ship.draw(g);
			laser.drawRectangle(g);
			int test1;

			while(count < 100)
      {
        //test1 = laser.getUpperLeft();
        //laser.setUpperLeftX(laser.getUpperLeft());
        laser.setUpperLeftY(laser.getUpperLeftY() - 5);

       // laser.setLowerRightX(laser.getLowerRightX());
        laser.setLowerRightY(laser.getLowerRightY() - 5);

        laser.drawRectangle(g);
         g.update();
         g.Sleep(1000);
        //SDL_Delay( 2000 );
        count++;
      }



char direction;
if(g.kbhit())
{
  //cout << g.getKey() << endl;

  ship.eraseSphere(g);
  direction = g.getKey();
  ship.moveSphere(direction);
  ship.draw(g);

  /*
  if(g.getKey() == 'M')
  {
    missile.draw(g);
    while (missile.getY() > 5)
    {
      missile.setY(missile.getY() - 5);
    }
    */
   // while(missile.getY() < 700)
   // {
    //  missile.moveProjectile();
   //   missile.eraseProjectile(g);
   // }
  //}




//cout << ship.getX() << " " << ship.getY() << endl;


}



			/*
			for(xd = 0; xd < 10 && x + xd < g.getCol(); xd++ ){
				for(yd = 0; yd < 10 && y + yd < g.getRow(); yd++ ){
					if(colored){
						g.plotPixel( x + xd, y + yd, R, G, B);
					}
					else{
					    g.plotPixel( x + xd, y + yd, 990, G, 990);
					}
				}
			}
			*/


		}

		if(g.kbhit()){
			g.getKey();
		}

		if(g.getMouseClick(x,y)){
			stopped = !stopped;
		}

		g.update();
    }
    return 0;
}

