#include<memory>
#include "window.h"

int main(int argc, char *argv[])
{
    std::unique_ptr<Window> u_pWindow = std::make_unique<Window>("Demo",640,580);
    
    u_pWindow->setBackgroundColor({ 255,255,255,255 });

    if(!u_pWindow->canShowWindow())
    {
        u_pWindow->freeResources();
        return -1;
    }

    u_pWindow->show();

    return 0;
}