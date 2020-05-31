#ifndef PLAYER_H
#define PLAYER_H

#include "rectangle.h"
#include<iostream>
class Player : public Rectangle
{
public:
	Player(int xPos,int yPos, int width, int height, Color color,int speed);
	void move(SDL_Keycode key);
	void move()
	{
		if(m_Rect.x <= 0)
			xSpeed = m_Speed;
		if(m_Rect.x + 40 >= 640)
			xSpeed = - m_Speed;
		
		if(m_Rect.y <= 0)
			ySpeed = m_Speed;
		if(m_Rect.y + 40 >= 580)
			ySpeed = - m_Speed;
		
		m_Rect.x += xSpeed;
		m_Rect.y += ySpeed;
	}
    
private:
	int m_Speed;
	int xSpeed = 0;
	int ySpeed = 0;
};
#endif PLAYER_H