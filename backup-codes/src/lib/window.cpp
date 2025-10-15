#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "window.h"

using namespace std;
/* yo I use vim btw ;) */


constexpr int ScreenWidth { 400 } ;
constexpr int ScreenHeight { 600 } ;


/*  */
bool init();

bool loadMedia();

void close();



/* global variables */
SDL_Window* window {nullptr};

SDL_Renderer* renderer {nullptr};

LazyTexture globalTexture;


LazyTexture::LazyTexture(){

  mTexture = nullptr ; 
  mWidth = 0 ; 
  mHeight = 0 ; 

}

LazyTexture::~LazyTexture(){

  destroy();

}

bool LazyTexture::loadFromFile( string path ){

  // Cleans up texture
  destroy();


  string imagePath{ "/Users/hibiki/Documents/Github/Inventory/src/lib/images/haikyuu1.jpg" };
  SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str() );
  if ( loadedSurface == nullptr ){

    SDL_Log( "Unable to load image %s! SDL_image error: %s\n", path.c_str(), SDL_GetError() );

  }

  //Create texture from surface
  mTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
  if(  mTexture == nullptr )
  {
    SDL_Log( "Unable to create texture from loaded pixels! SDL error: %s\n", SDL_GetError() );
  }
  else
  {
    //Get image dimensions
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;
  }

  //Clean up loaded surface
  SDL_DestroySurface( loadedSurface );

  // Returns success if texture is loaded 
  return mTexture != nullptr; 

}

void LazyTexture::destroy(){

  //Clean up texture
  SDL_DestroyTexture( mTexture );
  mTexture = nullptr;
  mWidth = 0;
  mHeight = 0;

} 

void LazyTexture::render(float x, float y){

  //Set texture position
  SDL_FRect dstRect{ x, y, static_cast<float>( mWidth ), static_cast<float>( mHeight ) };

  //Render texture
  SDL_RenderTexture( renderer, mTexture, nullptr, &dstRect );

}

int LazyTexture::getWidth(){

  return mWidth;

}

int LazyTexture::getHeight(){

  return mHeight;

}

bool LazyTexture::isLoaded(){

  return mTexture != nullptr;

}


bool init(){

  bool success { true };

  // Initialize the SDL for main window use purposes //
  if ( SDL_Init( SDL_INIT_VIDEO ) == false ){

    SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
    printf(" Error 001: Could not initialize SDL \n");
    success = false;
    return false;

  };


  // We check whether the window is created successfully //
  if ( SDL_CreateWindowAndRenderer( "SDL3 Tutorial: Textures and Extension Libraries", ScreenWidth, ScreenHeight, 0, &window, &renderer ) == false ) {

    SDL_Log( "SDL could not create window! SDL error: %s\n", SDL_GetError() );
    printf(" Error 002: Could not create SDL window \n");
    success = false;
    return false;

  };


  printf("The window is succesfully initialized\n");

  return success;

};


bool loadMedia(){

  /* This will be used a way to confirm loaded file */
  bool success { true };

  /* We set the string to the desired bitmap file we want to load then we initialize surface loading */

  if ( LazyTexture().loadFromFile( "/Users/hibiki/Documents/Github/Inventory/src/lib/resources/haikyuu1.png") ) {

    SDL_Log( "Unable to load image! SDL Error: Could not render png image" );
    printf( "Error 003: SDL could not load image to the screen \n" );
    success = false;
    return false;

  }

  printf("SDL Was able to load image to the screen\n");
  return success;

}


void close(){

  /* We clean up the surface of the screen */
  LazyTexture().destroy();


  /* Destroy the window */
  SDL_DestroyRenderer( renderer );
  renderer = nullptr;
  SDL_DestroyWindow( window );
  window = nullptr;


  /* I think "Quit" should be self explanatory enough right??? */
  SDL_Quit();

}




