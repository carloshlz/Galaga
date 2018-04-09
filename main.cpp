

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
    ship.setCenter(Point(350, 600));
    ship.setColor(Color(212, 20, 20));
    ship.setRadius(10);

    Color test;

    while (!g.getQuit())
    {
		if(!stopped)
		{
      //x = rand()%g.getCol();
			//y = rand()%g.getRow();
      //x = 20;
			//y = 20;

			//R = rand()%256;
			//G = rand()%256;
			//B = rand()%256;

			//g.getCol();
			//g.getRow();
			//g.plotPixel(x,y,R,G,B);
      //test = ship.getColor();

			//cout << test.R << endl;

			ship.draw(g);
			/*
char direction;
if(g.kbhit())
{
  cout << g.getKey() << endl;

    switch (direction)
    {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
    }
}

*/

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
