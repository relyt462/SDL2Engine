#ifndef GAMEOBJECTMANAGER
#define GAMEOBJECTMANAGER
#include <map>
#include <string>

class GameObject;
class SDL2Renderer;
class GameObjectManager{
protected:
    std::map<std::string,GameObject*> objects;
    SDL2Renderer* renderer;

public:
    GameObjectManager();
    ~GameObjectManager();
    void setRenderer(SDL2Renderer* renderer) {this->renderer = renderer;}
    void render(float interpolation);
    void update();
    GameObject* getObject(std::string objectName);
    void addObject(std::string objectName, GameObject* object);
protected:
};
#endif
