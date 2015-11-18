#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
/*
 * Description: Generic abstract input component currently only used for typechecking organization
 * Created: 11/17/15
*/
class InputComponent : public Component {
public:
    InputComponent (GameObject* parent) : Component(parent) {};
    virtual ~InputComponent ();
};
#endif
