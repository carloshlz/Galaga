//
//  Texture.h
//  SDL_Tutorial
//
//  Created by Carlos Hernandez on 4/11/18.
//  Copyright © 2018 Carlos Hernandez. All rights reserved.
//

#ifndef Texture_h
#define Texture_h

#include "SDL2/SDL.h"
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2_image/SDL_image.h>
#include "SDL_Plotter.h"
#include "Color.h"
#include "Sphere.h"
#include "Point.h"
#include "Rectangle.h"
#include "Projectile.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** TEXTURE CLASS STUFF **/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Loads media
bool loadMedia();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

class SpaceShipTexture
{
private:
    //The actual hardware texture
    SDL_Texture* ShipText;
    
    //Image dimensions
    int width;
    int height;
public:
    //Initializes variables
    SpaceShipTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );
    
    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL );
    
    //Gets image dimensions
    int getWidth();
    int getHeightx();
};

SpaceShipTexture::SpaceShipTexture()
{
    ShipText = NULL;
    width = 0;
    height = 0;
}

bool SpaceShipTexture::loadFromFile(string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface != NULL )
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture != NULL )
        {
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    //Return success
    ShipText = newTexture;
    return ShipText != NULL;

}

void SpaceShipTexture::render( int x, int y, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };
    
    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    //Render to screen
    SDL_RenderCopy( gRenderer, ShipText, clip, &renderQuad );
}

int SpaceShipTexture::getWidth()
{
    return width;
}
int SpaceShipTexture::getHeightx()
{
    return height;
}
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    
#endif /* Texture_h */
