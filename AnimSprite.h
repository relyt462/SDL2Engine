#ifndef ANIMSPRITE
#define ANIMSPRITE
#include "Sprite.h"

class AnimatedSprite : public Sprite {
protected:
    int numFrames;
    float timeForFrame;
    float timeInFrame;
    int curFrame;
    SDL_Rect[] spriteClips;
public:
    AnimatedSprite (std::string name);
    virtual ~AnimatedSprite ();
    void update(float elapsedSeconds);
//    void render(SDL2Renderer* renderer);
    bool generateTexture(std::string fileName, SDL2Renderer * renderer,
        int spriteHeight, int spriteWidth, int numColumns, int numRows,
        float timeForFrame);
protected:
    void nextFrame();
};

#endif
