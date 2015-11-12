#include "Win32SDL2Window.h"
#include <SDL_image.h>
#include "WindowConfig.h"
#include "SDL2Renderer.h"
Win32SDL2Window::Win32SDL2Window(){
    initialized = false;
    window = NULL;
    renderer = NULL;
    screenSurface = NULL;
}
Win32SDL2Window::~Win32SDL2Window(){
    cleanUpSDL();
}

//Initializes the window and displays it
//last modified : 10-19-15
//returns true if successful
bool Win32SDL2Window::init(WindowConfig config)
{
    windowConfig = config;
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        success = false;
    }
    else
    {
        this->window = SDL_CreateWindow(config.windowTitle.c_str(),
                            config.windowPosX,
                            config.windowPosY,
                            config.screenWidth,
                            config.screenHeight,
                            SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            success = false;
        }
        else
        {
            renderer = new SDL2Renderer(config.background);
            if(renderer->init(window))
            {
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags)) & imgFlags)
                {
                    success = false;
                }
                else
                {
                    screenSurface = SDL_GetWindowSurface(window);
                }
            }
            else
            {
                success = false;
            }
        }
    }
    initialized = success;
    return success;
}

void Win32SDL2Window::processEvents()
{
    if(!initialized)
    {
        return;
    }

    short nextGameTick = getNumberOfTicks();
    int loops;
    float interpolation;
    bool quit = false;
    SDL_Event event;
    //Game loop
    while(!quit)
    {
        //Message Loop
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
            //Handle other types of events here
        }
        //Update loop
        loops = 0;
        while(getNumberOfTicks() > nextGameTick && loops < MAX_FRAMESKIP)
        {
            update();

            nextGameTick += SKIP_TICKS;
            loops++;
        }
        interpolation = (float)(getNumberOfTicks() + SKIP_TICKS - nextGameTick) / (float)(SKIP_TICKS);

        renderer->renderBegin();
        render(interpolation);
        renderer->renderEnd();
    }
}

void Win32SDL2Window::cleanUpSDL()
{
    delete renderer;
    SDL_DestroyWindow(window);
    SDL_FreeSurface( screenSurface);
	screenSurface = NULL;
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}

int Win32SDL2Window::getNumberOfTicks()
{
    return ((float)SDL_GetTicks() /1000.0f) * (float)TICKS_PER_SECOND;
}
