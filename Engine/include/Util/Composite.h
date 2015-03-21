#ifndef COMPOSITE_H
#define COMPOSITE_H

#include"Rendering/GameWindow.h"

class Composite
{
public:
    Composite();
    virtual ~Composite();
    virtual bool HandleEvent(const sf::Event* event)=0;
    virtual void UpdateLogic()=0;
protected:
private:
};

#endif // COMPOSITE_H
