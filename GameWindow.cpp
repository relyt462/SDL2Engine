#include "GameWindow.h"
#include "Sprite.h"
#include "GameObjectManager.h"
GameWindow::GameWindow() : Win32SDL2Window()
{
    objectManager = new GameObjectManager();
}
GameWindow::~GameWindow()
{
    delete objectManager;
}

bool GameWindow::createStandardObjects()
{
    bool success = true;
    Sprite* object;
    SDL_Rect clipRect{0,0,100,100};
//    RGBA chromakey{0xFF,0xFF,0xFF,0xFF};
	object = new Sprite("dotUpperLeft");
    if(object->generateTexture("dotsTransparent.png",renderer, clipRect)){
        object->setVisible();
        objectManager->addObject("dotUpperLeft", object);
    }
    else
        success = false;
	object = new Sprite("dotUpperRight");
	object->setPosition(540, 0);
	clipRect = { 100,0,100,100 };
	if (object->generateTexture("dotsTransparent.png", renderer, clipRect)) {
		object->setVisible();
		objectManager->addObject("dotUpperRight", object);
	}
	else
		success = false;

    return success;
}

bool GameWindow::init(WindowConfig config)
{
    bool success = true;
    if(Win32SDL2Window::init(config))
    {
        objectManager->setRenderer(this->renderer);
        if(!createStandardObjects())
        {
            success = false;
        }
    }
    else
    {
        success = false;
    }
    return success;
}

void GameWindow::render()
{
    objectManager->render();
}
