#include "Rendering/RenderManager.h"
#include <iostream>
RenderManager::RenderManager()
{
    // ctor
    this->Worldbounds = new Dimension(1024, 768);
    cam = new Camera(0, 0, 640, 480);
}

RenderManager::~RenderManager()
{
}
Camera *RenderManager::GetCameraBounds() const
{
    return this->cam;
}
void RenderManager::SetWorldBounds(int x, int y)
{
    if (this->Worldbounds)
    {
        delete Worldbounds;
        Worldbounds = NULL;
    }
    Worldbounds = new Dimension(x, y);
}
void RenderManager::SetWorldBounds(const Dimension &wb)
{
    if (this->Worldbounds)
    {
        delete Worldbounds;
        Worldbounds = NULL;
    }
    Worldbounds = new Dimension(wb.Width(), wb.Height());
}
void RenderManager::UpdateCameraPosition(int x, int y)
{

    if (x > this->Worldbounds->Width() - cam->Width())
    {
        x = this->Worldbounds->Width() - cam->Width();
    }
    if (y > this->Worldbounds->Height() - cam->Height())
    {
        y = this->Worldbounds->Height() - cam->Height();
    }
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }

    this->cam->X(x);
    this->cam->Y(y);

    for (std::vector<Drawable *>::const_iterator it = m_drawables.begin(); it < m_drawables.end(); it++)
    {
        (*it)->UpdateCameraPosition(x, y);
    }
}
void RenderManager::DrawAll(const GameWindow &win)
{
    SortDrawablesByZOrder();
    for (std::vector<Drawable *>::const_iterator it = m_drawables.begin(); it < m_drawables.end(); it++)
    {
        Drawable *dbl;
        dbl = (*it);
        dbl->Draw(win);
    }
}
void RenderManager::AddDrawable(Drawable *dobj)
{
    if (dobj != NULL)
    {
        m_drawables.push_back(dobj);
        SortDrawablesByZOrder();
    }
}
void RenderManager::RemoveDrawable(Drawable *dobj)
{
    for (std::vector<Drawable *>::iterator it = m_drawables.begin(); it < m_drawables.end(); it++)
    {
        if ((*it) != NULL)
        {
            // remove reference, dont delete object
            m_drawables.erase(it);
            break;
        }
    }
}
void RenderManager::SortDrawablesByZOrder()
{
    for (unsigned int j = 0; j < m_drawables.size() - 1; j++)
    {
        for (unsigned int i = 0; i < m_drawables.size() - 1; i++)
        {
            if (m_drawables[i]->GetZPosition() > m_drawables[i + 1]->GetZPosition())
            {
                Drawable *temp = NULL;
                temp = m_drawables[i];
                m_drawables[i] = m_drawables[i + 1];
                m_drawables[i + 1] = temp;
            }
        }
    }
}
