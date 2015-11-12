#include "GameWindow.h"
#include "Sprite.h"
#include "AnimSprite.h"
#include "GameObjectManager.h"
GameWindow::GameWindow() : Win32SDL2Window()
{
    time = 0;
    objectManager = new GameObjectManager();
}
GameWindow::~GameWindow()
{
    delete objectManager;
}

bool GameWindow::createStandardObjects()
{
    bool success = true;
    GameObject* object;
    SDL_Rect clipRect{0,0,100,100};
//    RGBA chromakey{0xFF,0xFF,0xFF,0xFF};
	object = new Sprite("dotUpperLeft");
    if(((Sprite*)object)->generateTexture("dotsTransparent.png",renderer, clipRect)){
        object->setVisible();
        objectManager->addObject("dotUpperLeft", object);
    }
    else
        success = false;
	object = new Sprite("dotUpperRight");
	((Sprite*)object)->setPosition(540, 0);
	clipRect = { 100,0,100,100 };
	if (((Sprite*)object)->generateTexture("dotsTransparent.png", renderer, clipRect)) {
		object->setVisible();
		objectManager->addObject("dotUpperRight", object);
	}
	else
		success = false;
    object = new AnimatedSprite("AnimatedTest");
    ((AnimatedSprite*)object)->setPosition(120, 120);
    if(((AnimatedSprite*)object)->generateTexture("foo.png", renderer, 205, 64, 4, 1, 1));
    {
        object->setVisible();
        objectManager->addObject("AnimatedTest", object);
    }
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

void GameWindow::render(float interpolation)
{
    objectManager->render(interpolation);
}

void GameWindow::update()
{
    objectManager->update();
}
