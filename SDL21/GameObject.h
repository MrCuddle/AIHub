#pragma once
#include <SDL.h>
class GameObject
{
    virtual void update();
    virtual void draw(SDL_Renderer* ren);
};