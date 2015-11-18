#ifndef GRAPHICSCOMPONENT
#define GRAPHICSCOMPONENT
#include "Component.h"
class SDL2Renderer;
class Texture;
/*
 * Description: Abstract class for all grapical components
 * Created: 11/17/15
*/
class GraphicsComponent : public Component {
private:
    Texture* texture;
public:
    GraphicsComponent (GameObject* parent) : parent(parent) { texture = NULL };
    virtual ~GraphicsComponent () { delete this->texture };
    virtual void render(SDL2Renderer* renderer, float interpolation) = 0;
};
#endif
