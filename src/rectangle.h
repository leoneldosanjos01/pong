#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SDL.h>

struct Color
{
	int r;
	int g;
	int b;
	int a;
};


class Rectangle
{
public:
	Rectangle(int xPos,int yPos, int width, int height,Color color);

	void draw(SDL_Renderer* renderer) const;

	~Rectangle(){}
private:
	Color m_Color;
protected:
	SDL_Rect m_Rect;
};

#endif RECTANGLE_H