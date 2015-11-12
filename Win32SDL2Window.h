#ifndef WIN32SDL2WINDOW
#define WIN32SDL2WINDOW
#include <string>
#include <SDL.h>
#include "WindowConfig.h"

class SDL2Renderer;
class Win32SDL2Window{
    protected:
        SDL_Window* window;
        SDL_Surface* screenSurface;
        WindowConfig windowConfig;
        SDL2Renderer* renderer;
        bool initialized;
    private:
        const int TICKS_PER_SECOND = 60;
        const int SKIP_TICKS = 1000/TICKS_PER_SECOND;
        const int MAX_FRAMESKIP = 5;
    public:
        Win32SDL2Window();
        virtual ~Win32SDL2Window();

        virtual bool init(WindowConfig config);
        void processEvents();
    protected:
        void cleanUpSDL();
        virtual void render(float interpolation){  }
        virtual void update(){ }
    private:
        int getNumberOfTicks();
};

#endif
