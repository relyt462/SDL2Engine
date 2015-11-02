#include <SDL.h>
#include <stdio.h>
#include "GameWindow.h"

int main(int argc, char* args[])
{
    GameWindow window;
    WindowConfig config = {"TESTING",           //WindowTitle
                            640,                //WindowWidth
                            480,                //WindowHeight
                            100,                //WindowPositionX
                            100,                //WindowPositionY
                            {255,255,255,255}}; //BackgroundColor
	if (window.init(config))
	{
		window.processEvents();
		return 0;
	}
	return 1;
}
