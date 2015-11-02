#include "Sprite.h"
#include "Texture.h"
Sprite::Sprite(std::string name) : GameObject(name)
{
    this->texture = NULL;
    this->renderRect = new SDL_Rect();
    renderRect->x = 0;
    renderRect->y = 0;
    this->setNotVisible();
}

Sprite::~Sprite()
{
    delete this->texture;
    delete this->renderRect;
}

void Sprite::render(SDL2Renderer* renderer)
{
    if(this->texture)
    {
        renderer->renderTexture(texture, renderRect);
    }
}

void Sprite::update(float elapsedSeconds)
{

}

bool Sprite::generateTexture(std::string fileName, SDL2Renderer* renderer,SDL_Rect clipRect)
{
    renderRect->w = clipRect.w;
    renderRect->h = clipRect.h;
    texture = new Texture();
    return texture->generateTexture(fileName, renderer, SDL_BLENDMODE_BLEND, clipRect);
}

void Sprite::setPosition(int x, int y)
{
    renderRect->x = x;
    renderRect->y = y;
}
