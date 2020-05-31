#include "player.h"

Player::Player(int xPos,int yPos, int width, int height, Color color,int speed)
		:Rectangle(xPos,yPos,width,height,color),m_Speed(speed),xSpeed(speed),ySpeed(speed){}

void Player::move(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_LEFT:
        if((m_Rect.x - m_Speed) <= 5)
            return;
        m_Rect.x -= m_Speed;
        break;
    case SDLK_RIGHT:
        if((m_Rect.x + 200 + m_Speed) >= 640)
            return;
        m_Rect.x += m_Speed;
        break;
    default:
        break;
    }
}