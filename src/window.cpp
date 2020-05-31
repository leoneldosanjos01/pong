#include "window.h"
#include<vector>
#include<memory>

Window::Window(const char* title, int width, int height)
:m_WindowWidth(width),m_WindowHeight(height)
{
    SDL_Init(SDL_INIT_VIDEO);
    
    m_pWindow = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    if(m_pWindow != nullptr)
    {
        m_pRenderer = SDL_CreateRenderer(m_pWindow,-1,0);
        if(m_pRenderer != nullptr)
            mCanShowWindow = true;
    }
}

void Window::show()
{
    

    std::vector<Rectangle> rectangles;
    rectangles.reserve(16);
    
    int margin = 5;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            Rectangle rect((j * 40 + margin), 12 * i * 5, 40,40,Color { 0,255,0,0 });
            rectangles.push_back(rect);
            margin+=5;
        }
        margin = 5;
    }
    
    Player player(m_WindowWidth/2 - 100,m_WindowHeight - 50, 200,40,Color{255,0,0,0},1);
    Player player1(m_WindowWidth/2 - 100,m_WindowHeight/2, 40,40,Color{0,0,255,0},1);

    do
    {
        SDL_SetRenderDrawColor(m_pRenderer,m_BackgroundColor.r,m_BackgroundColor.g,m_BackgroundColor.b,m_BackgroundColor.a);
        SDL_RenderClear(m_pRenderer);
        
        SDL_PollEvent(&m_Event);
        if(m_Event.type == SDL_KEYDOWN)
        {
            player.move(m_Event.key.keysym.sym);
        }
        player.draw(m_pRenderer);

        player1.move();
        player1.draw(m_pRenderer);
        for(const auto& rect : rectangles)
            rect.draw(m_pRenderer);
        
        SDL_RenderPresent(m_pRenderer);
        SDL_Delay(5);
        
    }while(m_Event.type != SDL_QUIT);
}

void Window::freeResources()
{
    if(m_pWindow != nullptr)
    {
        SDL_DestroyWindow(m_pWindow);
        m_pWindow = nullptr;
    }

    if(m_pRenderer != nullptr)
    {
        SDL_DestroyRenderer(m_pRenderer);
        m_pRenderer = nullptr;
    }
    mCanShowWindow = false;
    SDL_Quit();
}