#include "rectangle.h"

Rectangle::Rectangle(int xPos,int yPos, int width, int height, Color color)
    :m_Rect({xPos,yPos,width,height}),m_Color(color){}

void Rectangle::draw(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer,m_Color.r,m_Color.g,m_Color.b,m_Color.a);
    SDL_RenderFillRect(renderer,&m_Rect);
    SDL_RenderDrawRect(renderer,&m_Rect);
}