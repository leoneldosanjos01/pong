#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include<iostream>
#include "rectangle.h"
#include "player.h"

class Window
{
public:
	Window(const char* title, int witdh, int height);

	void show();

	bool canShowWindow() const { return mCanShowWindow; }

	void freeResources();

	void setBackgroundColor( Color backgroundColor)
	{
		m_BackgroundColor = backgroundColor;
	}

	~Window()
	{
		freeResources();
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool mCanShowWindow = false;
	int m_WindowWidth,m_WindowHeight;
	Color m_BackgroundColor;
	SDL_Event m_Event;
};

#endif WINDOW_H