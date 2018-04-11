

#include <iostream>

#include "SDL_Plotter.h"
#include "Color.h"
#include "Sphere.h"
#include "Point.h"
#include "Projectile.h"



using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(700, 700);
    bool stopped = false;
    //bool colored = false;
    int x,y;
    int R,G,B;

    Sphere ship;
    Projectile missile;

    ship.setX(350);
    ship.setY(600);
    ship.setColor(Color(212, 20, 20));
    ship.setRadius(10);

    missile.setX(350);
    missile.setY(595);
    missile.setColor(Color(212, 20, 20));
    missile.setRadius(10);

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

    while (!g.getQuit())
    {
		if(!stopped)
		{

			ship.draw(g);



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
