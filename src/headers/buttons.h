#pragma once
#ifndef BUTTONS
#define BUTTONS


#endif
#include <master.h>
using namespace std;

static SDL_Renderer *localRenderer = {nullptr};

class Buttons
{

  public:
    Buttons(float x, float y, float w, float h);
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void create(SDL_Renderer *rendere) const;

  private:

    SDL_FRect rect[16];
    SDL_Color color{0, 0, 0, SDL_ALPHA_OPAQUE};

};

Buttons::Buttons(float x, float y, float w, float h):
  rect {x, y, w, h}
{}

void Buttons::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  color = SDL_Color{r, g, b, a};
}


void Buttons::create(SDL_Renderer *rendere)
const {
  SDL_SetRenderDrawColor(rendere, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(rendere, &rect[0]);
  SDL_SetRenderDrawColor(rendere, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderRect(rendere, &rect[0]);

}

