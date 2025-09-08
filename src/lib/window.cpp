#include <iostream>
#include <string>
#include "vendored/SDL/include/SDL3/SDL.h"
#include "vendored/SDL/include/SDL3/SDL_main.h"
#include "vendored/SDL/include/SDL3/SDL_video.h"
#include "resources/cv-image-bmp.bmp"
#include "headers.h"
using namespace std;



constexpr int ScreenWidth { 300 } ;
constexpr int ScreenHeight { 300 } ;



/* global variables */
SDL_Window* window {nullptr};

SDL_Surface* ScreenSurface {nullptr};

SDL_Surface* helloWorld {nullptr};



bool init(){

  bool success { true };

  // Initialize the SDL for main window use purposes //
  if ( SDL_Init( SDL_INIT_VIDEO ) == false ){

    SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
    printf(" Error 001: Could not initialize SDL \n");
    success = false;
    return false;

  };


  // Create the window with specified name and dimensions. //
  window = SDL_CreateWindow( "Fukc uuuuu", ScreenWidth, ScreenHeight, 0 );

  // We check whether the window is created succesfully //
  if ( window == nullptr ) {

    SDL_Log( "SDL could not create window! SDL error: %s\n", SDL_GetError() );
    printf(" Error 002: Could not create SDL window \n");
    success = false;
    return false;

  };


  ScreenSurface = SDL_GetWindowSurface( window );

  printf("The window is succesfully initialized\n");

  return success;

};


bool loadMedia(){

  bool success { true };

  /* We set the string to the desired bitmap file we want to load then we initialize surface loading */
  string imagePath { "resources/cv-image-bmp.bmp" };
  helloWorld = SDL_LoadBMP( imagePath.c_str() );

  if (  helloWorld == nullptr ){

    SDL_Log( "Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError() );
    printf( "Error 003: SDL could not load image to the screen \n" );
    success = false;
    return false;

  }

  printf("SDL Was able to load image to the screen\n");
  return success;

}


void close(){

  /* We clean up the surface of the screen */
  SDL_DestroySurface( helloWorld );
  helloWorld = nullptr;


  /* Destroy the window */
  SDL_DestroySurface( window );
  window = nullptr;
  ScreenSurface = nullptr;


  /* I think "Quit" should be self explanatory enough right??? */
  SDL_Quit();

}



