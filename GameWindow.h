#ifndef GAMEWINDOW
#define GAMEWINDOW
#include "Win32SDL2Window.h"

class GameObjectManager;
class GameWindow: public Win32SDL2Window{
    protected:
        GameObjectManager* objectManager;
        int time;
    public:
        GameWindow();
        ~GameWindow();
        void render(float interpolation);
        void update();
        bool createStandardObjects();
        bool init(WindowConfig config);
};
#endif
