#ifndef BUTTONS
#define BUTTONS


#endif
#include <master.h>


class Buttons
{

  public:
    Buttons();
    ~Buttons();

    int getHeight();
    int getWidth();

    void size(int w, int h);
    void destroy();
    void render(float x, float y);

    bool loadTexture(string path);
    bool isLoaded();

  private:

    SDL_Texture* mTexture;
    int width;
    int height;

};

Buttons::Buttons()
{

  mTexture {nullptr};
  width {0};
  height {0};

}

Buttons::~Buttons()
{

  destroy();

}

