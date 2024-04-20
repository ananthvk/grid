#ifndef GRID_HPP
#define GRID_HPP
#include "raylib.h"

class Grid
{
    int cell_size, rows, cols;

  public:
    Grid() : cell_size(10), rows(50), cols(50) {}

    void render(float offset_x, float offset_y);
};
#endif