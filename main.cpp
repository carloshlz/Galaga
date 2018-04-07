#include <iostream>

#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(600,900);
    bool stopped = false;
    bool colored = false;
    int x,y, xd, yd;
    int R,G,B;

    while (!g.getQuit())
    {
		if(!stopped)
		{
            x = rand()%g.getCol();
			y = rand()%g.getRow();
			R = rand()%256;
			G = rand()%256;
			B = rand()%256;

			//g.getCol();
			//g.getRow();
			g.plotPixel(x,y,R,G,B);

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
}
