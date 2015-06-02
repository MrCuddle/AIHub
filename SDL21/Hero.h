#pragma once
#include "GameObject.h"

class Hero : public GameObject
{
public:
    Hero(int posX, int posY) : GameObject(posX, posY, 16, 16, glm::uvec4(210,0,0,255))
    {

    }

    void update()
    {
        const Uint8* keyState = SDL_GetKeyboardState(NULL);

        if(keyState[SDL_SCANCODE_W])
            pos += glm::vec2(0,-1) * 2.5f;
        if( keyState[SDL_SCANCODE_S] )
            pos += glm::vec2( 0, 1 ) * 2.5f;
        if( keyState[SDL_SCANCODE_A] )
            pos += glm::vec2( -1, 0 ) * 2.5f;
        if( keyState[SDL_SCANCODE_D] )
            pos += glm::vec2( 1, 0 ) * 2.5f;
    }

    void draw(SDL_Renderer* ren)
    {
        GameObject::draw(ren);
    }
};