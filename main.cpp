

#include <iostream>

#include "SDL_Plotter.h"
#include "Color.h"
#include "Sphere.h"
#include "Point.h"


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

    Color test;

    while (!g.getQuit())
    {
		if(!stopped)
		{

			ship.draw(g);

char direction;
if(g.kbhit())
{
  cout << g.getKey() << endl;
  ship.eraseSphere(g);
  direction = g.getKey();
  ship.moveSphere(direction);
  ship.draw(g);


cout << ship.getX() << " " << ship.getY() << endl;


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
