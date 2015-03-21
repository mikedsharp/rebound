#include "Util/Camera.h"

Camera::Camera(int x, int y, int width, int height)
{
    //ctor
    this->m_cameraX = x;
    this->m_cameraY = y;
    this->m_cameraWidth = width;
    this->m_cameraHeight = height;
}

Camera::~Camera()
{
    //dtor
}
