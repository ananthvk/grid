#ifndef GRID_HPP
#define GRID_HPP
#include "raylib.h"
#include <vector>

class GridBuilder;

class Grid
{
    // All measurements are in pixels, top left corner is cell (0, 0)

    int rows, cols, cell_size;

    // When color of each cell is different
    std::vector<Color> cell_colors;
    std::vector<Color> hover_colors;

    // Common cell color for all cells
    Color cell_color;
    Color hover_color;
    Color border_horizontal_color;
    Color border_vertical_color;

    float thickness_horizontal;
    float thickness_vertical;

  public:
    Grid();

    void render(float offset_x, float offset_y);
    friend class GridBuilder;
};

class GridBuilder
{
    Grid grid;

  public:
    GridBuilder &rows(int r);
    GridBuilder &cols(int c);
    GridBuilder &cell_size(int sz);
    GridBuilder &cell_color(Color col);
    GridBuilder &hover_color(Color col);
    GridBuilder &border_horizontal_color(Color col);
    GridBuilder &border_vertical_color(Color col);
    GridBuilder &thickness_horizontal(float thickness);
    GridBuilder &thickness_vertical(float thickness);
    Grid build();
};
#endif