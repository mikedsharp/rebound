#include "Rendering/GameSprite.h"

#include<iostream>

GameSprite::~GameSprite()
{
    //dtor
    if(m_wrappedSprite)
    {
        delete m_wrappedSprite;
        m_wrappedSprite = NULL;
    }
    if(m_bounds)
    {
        delete m_bounds;
        m_bounds = NULL;
    }

}
GameSprite::GameSprite(const Rect&  dimensions , const Point&  clipLocation , const sf::Image& spriteSheet)
{
        // init the inner sprite, setup start params
        m_wrappedSprite = new sf::Sprite();
        this->m_worldX = dimensions.X();
        this->m_worldY = dimensions.Y();

        this->m_bounds = new RotatedRectangle(Rect(dimensions.X(),dimensions.Y(), dimensions.Width(), dimensions.Height()), 0.0f);

        this->m_width = dimensions.Width();
        this->m_height = dimensions.Height();
        this->m_clipX = clipLocation.X();
        this->m_clipY  = clipLocation.Y();

        m_wrappedSprite->setPosition(m_worldX, m_worldY);
        m_wrappedSprite->setImage(spriteSheet);
        m_wrappedSprite->SetSubRect(sf::IntRect(m_clipX,
                                                m_clipY,
                                                this->m_clipX+this->m_width,
                                                this->m_clipY+this->m_height));
        XSpeed(0);
        YSpeed(0);
        m_xSpeed = m_ySpeed = 0;
        m_visible = true;
        m_alive = true;

        m_animationTimer.restart();
        m_numFrames = (m_wrappedSprite->GetImage()->GetWidth())/(this->Bounds().Width());
        m_currentFrame = 1;
        m_animationDelay = 0.05;

        Animating(false);
}

void GameSprite::Move(int direction)
{
    switch(direction)
    {
        case DIRECTION_UP:
        {
            SetPosition(m_worldX,m_worldY - YSpeed());
            break;
        }
        case DIRECTION_DOWN:
        {
            SetPosition(m_worldX,m_worldY + YSpeed());
            break;
        }
        case DIRECTION_LEFT:
        {
            SetPosition(m_worldX - XSpeed(),m_worldY);
            break;
        }
        case DIRECTION_RIGHT:
        {
            SetPosition(m_worldX + XSpeed(),m_worldY);
            break;
        }
        case DIRECTION_AUTO:
        {
            SetPosition(m_worldX + XSpeed(),m_worldY + YSpeed());
            break;
        }
        default:
        {
            // invalid direction
            break;
        }
    }
}
void GameSprite::Move(float offsetX, float offsetY)
{
    SetPosition(m_worldX + offsetX,m_worldY + offsetY);
}

void GameSprite::SetAnimation(int action)
{
    this->SetClipPosition(0, action * this->Bounds().Height());
}
void GameSprite::SetSize(int width, int height)
{
    this->m_width = width;
    this->m_height = height;
    m_wrappedSprite->SetSubRect(sf::IntRect(m_clipX,m_clipY,width,height));
}
void GameSprite::SetSpritesheet(const sf::Image& spriteSheet)
{
    m_wrappedSprite->SetImage(spriteSheet);
}
void GameSprite::SetClipPosition(int x, int y)
{
    this->m_clipX = x;
    this->m_clipY = y;
    m_wrappedSprite->SetSubRect(sf::IntRect(m_clipX,m_clipY,this->m_clipX+this->m_width,this->m_clipY+this->m_height));
}
void GameSprite::SetPosition(float x, float y)
{
    this->SetWorldPosition(x, y);
    this->m_wrappedSprite->setPosition((m_worldX - m_cameraX), (m_worldY - m_cameraY));
    m_bounds->X(x);
    m_bounds->Y(y);
}
void GameSprite::SetDimensions(int x, int y, int width, int height)
{
    SetPosition(x,y);
    SetSize(width,height);
}
bool GameSprite::Collision(const RotatedRectangle& obstacle)
{
    if(Alive()){
         if(obstacle.Rotation() == 0 && Bounds().Rotation() == 0){
            int leftA, leftB;
            int rightA, rightB;
            int topA, topB;
            int bottomA, bottomB;

            // variables to make the function more readable
            leftA = this->m_worldX;
            rightA = this->m_worldX + this->m_width;
            topA = this->m_worldY;
            bottomA = this->m_worldY + this->m_height;

            leftB = obstacle.X();
            rightB = obstacle.X()+obstacle.Width();
            topB = obstacle.Y();
            bottomB = obstacle.Y() + obstacle.Height();

            // if this evaluates to true, there's no collision, returns false
            if(leftA > rightB ||
                    rightA < leftB ||
                    topA > bottomB ||
                    bottomA < topB)
            {
                return false;
            }
            return true;
        }
        else if(Bounds().Collision(obstacle))
        {
            return true;
        }
        else{
                return false;
        }
    }

    return false;
}
void GameSprite::Draw(const GameWindow& win)
{
            if(Visible())
            {
                win.Draw(this);
            }
            if(Animating())
            {
                  if(m_animationTimer.getElapsedTime().asSeconds() >= m_animationDelay)
                    {
                       (m_currentFrame >= (m_numFrames-1))?  m_currentFrame = 0: m_currentFrame += 1;
                       SetClipPosition( m_currentFrame*this->Bounds().Width(),m_clipY);
                       m_animationTimer.restart();

                    }
            }

}
void GameSprite::UpdateCameraPosition(float x, float y)
{
    this->m_cameraX = x;
    this->m_cameraY = y;
    this->SetPosition(m_worldX, m_worldY);
}

