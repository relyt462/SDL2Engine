#ifndef SDL2RENDERWHITTIN
#define SDL2RENDERWHITTIN

#include <SDL.h>
#include "WindowConfig.h"
#include "RGB.h"

class Texture;
class SDL2Renderer {

protected:
    SDL_Renderer* renderer;
    RGBA background;
public:
    SDL2Renderer (RGBA background);
    virtual ~SDL2Renderer ();
    bool init(SDL_Window* window);
    void renderBegin();
    void renderEnd();
    SDL_Texture* createTextureFromSurface(SDL_Surface * surface);
    void renderTexture(Texture* texture, SDL_Rect* renderQuad);

protected:
    void cleanUpSDL();
};

#endif
