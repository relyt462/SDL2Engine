#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <string>
#include "SDL2Renderer.h"

class GameObject{
    protected:
        bool visible;
        std::string name;
    public:
        GameObject(std::string name):name(name) {};
        virtual ~GameObject() {};
        virtual void update(){};
        virtual void render(SDL2Renderer* renderer, float interpolation){};
        void setVisible() { visible = true; };
        void setNotVisible() { visible = false; };
        bool isVisible() { return visible; };
};

#endif
