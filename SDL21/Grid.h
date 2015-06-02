#pragma once

#include <SDL.h>
#include <glm/glm.hpp>
#include <algorithm>
#include <vector>

struct NodeData
{
    int gValue, hValue;
};
class Grid
{
public:
    Grid(int sizeX, int sizeY, int width, int height) : gridSizeX(sizeX), gridSizeY(sizeY), nodeWidth(width), nodeHeight(height)
    {
        nodes.resize(gridSizeX);
        for(auto& elem: nodes)
        {
            elem.resize(gridSizeY);
        }

        nodes[gridSizeX/2][gridSizeY/2].gValue = 500;
        nodes[5][0].gValue = 500;
        nodes[0][5].gValue = 500;
    }

    ~Grid()
    {
    }

    void draw(SDL_Renderer* ren)
    {
        SDL_SetRenderDrawColor(ren, 148,0,211, 255);
        for(int i = 0; i < gridSizeX; i++)
        {
            for(int j = 0; j < gridSizeY; j++)
            {
                SDL_Rect drawRect {i * nodeWidth, j*nodeHeight, nodeWidth, nodeHeight};
                if(nodes[i][j].gValue > 50)
                    SDL_RenderFillRect(ren, &drawRect);
                else
                    SDL_RenderDrawRect(ren, &drawRect);
            }
        }
    }

    glm::ivec2 calculateGridPos(const glm::vec2& posIn)
    {
        return glm::ivec2(std::max(0,std::min(static_cast<int>(posIn.x / nodeWidth), gridSizeX - 1)), std::max(0,std::min(static_cast<int>(posIn.y / nodeHeight), gridSizeY - 1)));
    }
private:
    int gridSizeX, gridSizeY, nodeWidth, nodeHeight;
    std::vector<std::vector<NodeData>> nodes;

};