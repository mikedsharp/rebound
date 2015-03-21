#ifndef FOCUSABLE_H
#define FOCUSABLE_H

#include<Util/Camera.h>

class Focusable
{
    public:
        Focusable();
        virtual ~Focusable();
        virtual Camera* GetCameraBounds()=0;
    protected:
    private:
};

#endif // FOCUSABLE_H
