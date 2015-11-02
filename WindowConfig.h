#ifndef WINDOWCONFIG
#define WINDOWCONFIG
#include <string>
#include "RGB.h"

struct WindowConfig{
    public:
        std::string windowTitle;
        int screenWidth;
        int screenHeight;
        int windowPosX;
        int windowPosY;
        RGBA background;
};

#endif
