#include <iostream>
#include <string>
#include "vendored/SDL/include/SDL3/SDL.h"
#include "vendored/SDL/include/SDL3/SDL_main.h"
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
    printf(" Error 001: Could not initialize SDL");
    success = false;

  };

  // Create the window with specified name and dimensions. //
  window = SDL_CreateWindow( "Fukc uuuuu", ScreenWidth, ScreenHeight, 0);

  // Create the window with specified name and dimensions. //
  if ( window == nullptr ) {

    SDL_Log( "SDL could not create window! SDL error: %s\n", SDL_GetError() );
    printf(" Error 002: Could not create SDL window");
    success = false;

  };

  ScreenSurface = SDL_GetWindowSurface( window );

  printf("The window is succesfully initialized\n\n");

  return success;

};


bool loadMedia(){

  return false;

}


void close(){


}



