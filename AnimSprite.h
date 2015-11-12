#ifndef ANIMSPRITE
#define ANIMSPRITE
#include "Sprite.h"

class AnimatedSprite : public Sprite {
protected:
    int numFrames;
    int ticksForFrame;
    int ticksInFrame;
    int curFrame;
    SDL_Rect * spriteClips;
public:
    AnimatedSprite (std::string name);
    virtual ~AnimatedSprite ();
    void update();
    bool generateTexture(std::string fileName, SDL2Renderer * renderer,
        int spriteHeight, int spriteWidth, int numColumns, int numRows,
        int timeForFrame);
protected:
    void nextFrame();
};

#endif
