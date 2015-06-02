#include <iostream>
#include <SDL.h>
#include "Hero.h"
#include "Grid.h"
#include <glm/glm.hpp>
#include <string>

int main(int, char**){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    bool quit = false;
    Hero h(8,8);
    Grid grid(20,15,32,32);

    while (!quit){
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
            }
        }


        h.update();
        glm::ivec2 posInGrid = grid.calculateGridPos(h.getPos());
        std::string winTitle = "Position in grid ";
        winTitle += "x : ";
        winTitle += std::to_string(posInGrid.x);
        winTitle += " y : ";
        winTitle += std::to_string(posInGrid.y);
        SDL_SetWindowTitle(win, winTitle.c_str());
        SDL_SetRenderDrawColor(ren, 90,90,90,255);
        SDL_RenderClear(ren);
        h.draw(ren);
        grid.draw(ren);
        SDL_RenderPresent(ren);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}