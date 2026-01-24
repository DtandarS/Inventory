
//
//  maker.cpp
//  Inventory
//
//  Created by Tom Naksutti on 21.10.2025.
//

#define SDL_MAIN_USE_CALLBACKS 1 
#include <master.h>

using namespace std;

#define WIDTH 600
#define HEIGHT 800

static SDL_Window *window = { nullptr };
static SDL_Renderer *renderer = { nullptr };
static SDL_Surface *surface = { nullptr };
static SDL_Texture *texture = { nullptr };
static int texture_width = 0;
static int texture_height = 0;
constexpr int TargetFPS = 60;
constexpr float TargetFrameTime = 1000 / TargetFPS;
Buttons buttons{100.0f, 200.0f, 1000.0f, 100.0f};
int x = 1;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

  SDL_Surface *surface = NULL;
  char *path;

  SDL_SetAppMetadata("tomsan chilli huone", "1.0", "meow");

  // initializing SDL
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("couldn't initialize SDL's video module %s \n", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  
  // Creating window
  if (!SDL_CreateWindowAndRenderer("I went insane", HEIGHT, WIDTH, SDL_WINDOW_RESIZABLE, &window, &renderer))
  {
    SDL_Log("Couldn't create SDL window. SDL_Error %s \n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  //I have no clue what this does but it looks cool.
  SDL_SetRenderLogicalPresentation(renderer, WIDTH, HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

  // Setting rendering image path
  SDL_asprintf(&path, "%simages/kenma3.jpg", SDL_GetBasePath());
  surface = IMG_Load(path);
  if (!surface)
  {
    SDL_Log("SDL couldn't load the image on to the surface %s \n", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  SDL_free(path);

  texture_width = surface->w;
  texture_height = surface->h;

  // Loading image to the surface 
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture)
  {
    SDL_Log("SDL couldn't render image to the surface %s \n", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  SDL_DestroySurface(surface);


  return SDL_APP_CONTINUE;

}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

SDL_AppResult SDL_AppIterate(void *appstate)
{

  SDL_FRect dst_rect;
  const Uint64 frame = SDL_GetTicks();

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  /* center this one. */

  /*
  dst_rect.x = ((float) (WIDTH - texture_width)) / 2.0f;
  dst_rect.y = ((float) (HEIGHT - texture_height)) / 2.0f;
  dst_rect.w = (float) texture_width;
  dst_rect.h = (float) texture_height;
  SDL_RenderTexture(renderer, texture, NULL, &dst_rect);
  */

  SDL_RenderPresent(renderer);

  buttons.setColor(250, 255, 255, 255);
  buttons.create(renderer);

  SDL_RenderPresent(renderer);

  int RealFrameTime = SDL_GetTicks() - frame;
  if( RealFrameTime < TargetFrameTime)
  {
    SDL_Delay(TargetFrameTime - RealFrameTime);
  }

  return SDL_APP_CONTINUE;

}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

  SDL_DestroyTexture(texture);

}
