#ifndef COMPONENT
#define COMPONENT
#include <queue>
#include "GameObject"
/*
 * Contains abstract component classs
 * Created: 11/17/15
 * Not modified since creation
*/

/*
 * Description: Types of messages
 * Created: 11/17/15
*/
enum MessageType
{

};

/*
 * Description: General struct for messages
 * Created: 11/17/15
*/
struct Message
{
    MessageType type;
    int data;
};

/*
 * Description: Abstract class for game object components
 * Created: 11/17/15
*/
class Component
{
protected:
    //GameObject who owns this
    GameObject* parent;
    //Queue of messages
    std::queue<Message> messageQueue;

public:
    Component(GameObject* parent): parent(parent) {  };
    virtual ~Component() = 0;
    //Send to components attached to parent object, not implemented yet
    virtual void send(Message message) = 0;
    //Receive a message, up to individual components to handle queue in update
    virtual void receive(Message message) { messageQueue.push(message); }
    virtual void update() = 0;
protected:
};
#endif
