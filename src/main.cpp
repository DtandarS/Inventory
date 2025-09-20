/* This program is build using and following lazy foo's production tutorial. All appriciation goes to him and his code. */
/* oh yeah. I use vim btw */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "lib/headers.h"
#include "lib/vendored/SDL/include/SDL3/SDL.h"

bool boo = true;
int n, m, y;


int main( int argc, char* args[]){

  /* We initialize a final exit code */
  int exitCode{ 0 };


  if ( init() == false ){

    SDL_Log(" Unable to initialize the program \n ");
    exitCode = 1; 
    return 0;

  };

  if ( loadMedia() == false ){

    SDL_Log(" Unable to load media on the the screen \n ");
    exitCode = 2;
    return 0;

  };

  bool quit{ false };
  SDL_Event e;
  SDL_zero( e );

  while ( quit == false ){

    while ( SDL_PollEvent( &e ) == true ){ 

      if ( e.type == SDL_EVENT_QUIT ){

        quit = true;

      } 

    }

    fillSurface();
    renderImage();
    updateSurface();

  }


close();
return exitCode;

}


