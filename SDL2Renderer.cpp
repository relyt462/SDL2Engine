#include "SDL2Renderer.h"
#include "Texture.h"

SDL2Renderer::SDL2Renderer(RGBA background): background(background)
{

}
SDL2Renderer::~SDL2Renderer()
{
    cleanUpSDL();
}

void SDL2Renderer::renderBegin()
{
    SDL_SetRenderDrawColor(renderer,
                            background.red,
                            background.blue,
                            background.green,
                            background.alpha);
    SDL_RenderClear(renderer);
}
void SDL2Renderer::renderEnd()
{
    SDL_RenderPresent(renderer);
}

void SDL2Renderer::cleanUpSDL()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
}

bool SDL2Renderer::init(SDL_Window * window)
{
    bool success = true;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        success = false;
    }
    else
    {
        SDL_SetRenderDrawColor(renderer,
            background.red,
            background.green,
            background.blue,
            background.alpha);
    }
    return success;
}

SDL_Texture* SDL2Renderer::createTextureFromSurface(SDL_Surface* surface)
{
    return SDL_CreateTextureFromSurface(renderer, surface);
}

void SDL2Renderer::renderTexture(Texture* texture, SDL_Rect* renderQuad)
{
    SDL_RenderCopy(renderer, texture->getTexture(), texture->getClip(), renderQuad);
}
