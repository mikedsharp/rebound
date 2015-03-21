#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include<vector>
#include"Rendering/Drawable.h"
#include<Util/Rect.h>
#include<Util/Dimension.h>
#include<Util/Camera.h>


class RenderManager
{
    public:
        RenderManager();
        virtual ~RenderManager();
        void DrawAll(const GameWindow& win);
        void AddDrawable(Drawable* dobj);
        void RemoveDrawable(Drawable* dobj);
        void UpdateCameraPosition(int x, int y);
        void SetCameraBounds(const Rect& worldBounds);
        Camera* GetCameraBounds()const;
        void SetWorldBounds(int x, int y);
        void SetWorldBounds(const Dimension& wb);
        void SortDrawablesByZOrder();

    protected:
    private:
        std::vector<Drawable*> m_drawables;
        // camX and camY are the cameras world co-ordinates
        //int camX,  camY, camWidth, camHeight;
        Camera* cam;
        // the bounds are the bounds the camera must stay within in the world
        Dimension* Worldbounds;


};

#endif // RENDERMANAGER_H
