#include "Rendering/Drawable.h"

Drawable::Drawable()
{
    //ctor
    m_z = 0;
    m_cameraX = 0;
    m_cameraY = 0;
    m_worldX = m_worldY = 0;
}

Drawable::~Drawable()
{
    //dtor
}
void Drawable::SetWorldPosition(float x, float y)
{
    this->m_worldX = x;
    this->m_worldY = y;
}
