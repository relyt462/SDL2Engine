#include "AnimSprite.h"
#include "Texture.h"
AnimatedSprite::AnimatedSprite(std::string name) : Sprite(name)
{
    spriteClips = NULL;
}

AnimatedSprite::~AnimatedSprite()
{
    if(spriteClips != NULL)
    {
        delete[] spriteClips;
    }
}

void AnimatedSprite::update()
{
    if(ticksInFrame > ticksForFrame)
    {
        nextFrame();
    }
    ticksInFrame++;
}

bool AnimatedSprite::generateTexture(std::string fileName, SDL2Renderer* renderer,
    int spriteHeight, int spriteWidth, int numColumns, int numRows, int ticksForFrame)
{
    renderRect->w = spriteWidth;
    renderRect->h = spriteWidth;
    numFrames = numColumns * numRows;
    spriteClips = new SDL_Rect[numFrames];
    int frameIndex = 0;
    for(int i = 0; i < numRows; ++i)
    {
        for(int j = 0; j < numColumns; ++j)
        {
            spriteClips[frameIndex++] = {j * spriteWidth, i * spriteHeight, spriteWidth, spriteHeight};
        }
    }
    this->ticksForFrame = ticksForFrame;
    texture = new Texture();
    return texture->generateTexture(fileName, renderer, SDL_BLENDMODE_BLEND, spriteClips[0]);
}

void AnimatedSprite::nextFrame()
{
    ++curFrame;
    if(curFrame >= numFrames)
    {
        curFrame = 0;
    }
    texture->setClip(spriteClips[curFrame]);
    this->ticksInFrame = 0;
}
