#include "GameObjectManager.h"
#include "GameObject.h"
#include "SDL2Renderer.h"
#include "Sprite.h"

GameObjectManager::GameObjectManager() {  }

GameObjectManager::~GameObjectManager()
{
    for(auto it = objects.begin(); it != objects.end(); ++it)
    {
        delete it->second;
    }
}

void GameObjectManager::render()
{
    for(auto it = objects.begin(); it != objects.end(); ++it)
    {
        if(it->second->isVisible())
            it->second->render(renderer);
    }
}

void GameObjectManager::update(float elapsedSeconds)
{
    for(auto it = objects.begin(); it != objects.end(); ++it)
    {
        it->second->update(elapsedSeconds);
    }
}

GameObject* GameObjectManager::getObject(std::string objectName)
{
    auto it = objects.find(objectName);
    if(it != objects.end())
    {
        return it->second;
    }
    else
    {
        return NULL;
    }
}

void GameObjectManager::addObject(std::string name, GameObject* object)
{
    objects[name] = object;
}
