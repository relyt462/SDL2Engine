#ifndef WIN32SDL2WINDOW
#define WIN32SDL2WINDOW
#include <string>
#include <SDL.h>
#include "WindowConfig.h"

class SDL2Renderer;
class Win32SDL2Window{
    public:
        Win32SDL2Window();
        virtual ~Win32SDL2Window();

        virtual bool init(WindowConfig config);
        void processEvents();
    protected:
        void cleanUpSDL();
        virtual void render(){  }
    protected:
        SDL_Window* window;
        SDL_Surface* screenSurface;
        WindowConfig windowConfig;
        SDL2Renderer* renderer;
        bool initialized;
};

#endif
