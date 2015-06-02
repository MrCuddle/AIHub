#pragma once
#include <SDL.h>
#include <glm/glm.hpp>
class GameObject
{
public:
    GameObject(int posX = 0, int posY = 0, int objWidth = 40, int objHeight = 40, const glm::uvec4& objColor = glm::uvec4(0,0,0,255)) : pos(posX,posY), width(objWidth), height(objHeight), color(objColor)
    {
    }
    virtual void update()
    {

    }

    virtual void draw(SDL_Renderer* ren)
    {
        SDL_SetRenderDrawColor(ren, color.r,color.g,color.b,color.a);
        SDL_Rect drawRect { pos.x - width / 2, pos.y - height / 2, width, height};
        SDL_RenderFillRect(ren, &drawRect);
    }

    glm::vec2 getPos()
    {
        return pos;
    }
protected:
    glm::vec2 pos;
    glm::uvec4 color;
    int width, height;
};