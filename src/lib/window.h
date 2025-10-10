
#ifndef WINDOW_H
#define WINDOW_H
#include "SDL/include/SDL3/SDL.h"
#include "SDL_image/include/SDL3_image/SDL_image.h"

class LazyTexture{

  public: 

    // Variable Initialization
    LazyTexture();

    // Cleans up the variable
    ~LazyTexture();

    // finds the variable from machine
    bool loadFromFile( string path );

    // cleans up the texture
    void destroy();

    // Draws the texture
    void render( float x, float y );

    int getWidth();
    int getHeight();
    bool isLoaded();

  private:

    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;

}; 




#endif
