#ifndef SDL2TIMER
#define SDL2TIMER

class SDL2Timer{
protected:
    unsigned long startTime;
    unsigned long pausedTime;
    int ticksPerSecond;
    bool running;
    bool paused;
public:
    SDL2Timer(int ticksPerSecond);
    ~SDL2Timer();
    void start();
    void pause();
    int getTicks();
    unsigned long getMilliseconds();
    bool isRunning();
    bool isPaused();
};
#endif
