#include "grid.hpp"

void Grid::render(float offset_x, float offset_y)
{
    // If there are n rows, n+1 lines should be drawn
    for (int i = 0; i <= rows; i++)
    {
        DrawLineEx({offset_x, (float)i * cell_size + offset_y},
                   {offset_x + (float)cols * cell_size, offset_y + (float)i * cell_size}, 2,
                   {255, 0, 0, 255});
    }
    for (int i = 0; i <= cols; i++)
    {
        DrawLineEx({offset_x + (float)i * cell_size, offset_y},
                   {offset_x + (float)i * cell_size, offset_y + (float)rows * cell_size}, 2,
                   {0, 0, 255, 255});
    }
}