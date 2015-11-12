#include "SDL2Timer.h"
#include "SDL2.h"
SDL2Timer(int ticksPerSecond) : ticksPerSecond(ticksPerSecond)
{
    running = false;
    paused = false;
    startTime = 0;
    pausedTime = 0;
}
~SDL2Timer(){   }
void start()
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
void pause()
{
    if(running)
    {
        pausedTime = getMilliseconds() - startTime;
        paused = true;
    }
}
int getTicks()
{
    unsigned long timeInMs = getMilliseconds();
    return (int)(((float)timeInMs/1000.0f) * 60.0f); 
}
unsigned long getMilliseconds()
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
bool isRunning()
{
    return running;
}
bool isPaused()
{
    return paused;
}
