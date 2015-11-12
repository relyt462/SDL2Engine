#include "SDL2Timer.h"
#include <SDL.h>
SDL2Timer::SDL2Timer(int ticksPerSecond) : ticksPerSecond(ticksPerSecond)
{
    running = false;
    paused = false;
    startTime = 0;
    pausedTime = 0;
}
SDL2Timer::~SDL2Timer(){   }
void SDL2Timer::start()
{
    if(paused)
    {
        int startTime = SDL_GetTicks() - pausedTime;
        pausedTime = 0;
    }
    else
    {
        int startTime = SDL_GetTicks();
    }
    running = true;
}
void SDL2Timer::pause()
{
    if(running)
    {
        pausedTime = getMilliseconds() - startTime;
        paused = true;
    }
}
int SDL2Timer::getTicks()
{
    unsigned long timeInMs = getMilliseconds();
    return (int)(((float)timeInMs/1000.0f) * 60.0f);
}
unsigned long SDL2Timer::getMilliseconds()
{
    unsigned long timePassed = 0;
    if(running)
    {
        if(paused)
        {
            timePassed = pausedTime;
        }
        else
        {
            timePassed = SDL_GetTicks() - startTime;
        }
    }
    return timePassed;
}
bool SDL2Timer::isRunning()
{
    return running;
}
bool SDL2Timer::isPaused()
{
    return paused;
}
