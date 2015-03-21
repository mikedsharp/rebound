#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
        Camera(int x, int y, int width, int height);
        ~Camera();
        int X()const{return m_cameraX;}
        int Y()const{return m_cameraY;}
        int Width()const{return m_cameraWidth;}
        int Height()const{return m_cameraHeight;}

        void X(int x){this->m_cameraX = x;}
        void Y(int y){this->m_cameraY = y;}
        void Width(int width){this->m_cameraWidth = width;}
        void Height(int height){this->m_cameraHeight = height;}

    protected:
    private:
    int m_cameraY;
    int m_cameraX;
    int m_cameraWidth;
    int m_cameraHeight;
};

#endif // CAMERA_H
