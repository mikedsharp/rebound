#ifndef DIMENSION_H
#define DIMENSION_H


class Dimension
{
    public:
        Dimension(int width, int height);
        virtual ~Dimension();
        void Width(int width){this->m_width = width;}
        void Height(int height){this->m_height = height;}

        int Width()const{return m_width;}
        int Height()const{return m_height;}
    protected:
    private:
    int m_width;
    int m_height;
};

#endif // DIMENSION_H
