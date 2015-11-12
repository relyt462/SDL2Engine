#ifndef SPRITE
#define SPRITE
#include "GameObject.h"
#include <string>
class Texture;
struct RGBA;
class Sprite : public GameObject
{
    protected:
        Texture* texture;
        SDL_Rect* renderRect;
    public:
        Sprite(std::string name);
        ~Sprite();
        virtual void render(SDL2Renderer* renderer, float interpolation);
        virtual void update();
        virtual bool generateTexture(std::string fileName, SDL2Renderer * renderer, SDL_Rect clipRect);
        virtual void setPosition(int x,int y);
    protected:

};

#endif
