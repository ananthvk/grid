#include "grid.hpp"

void Grid::render(float offset_x, float offset_y)
{
    // If there are n rows, n+1 lines should be drawn
    if (thickness_horizontal)
        for (int i = 0; i <= rows; i++)
        {
            DrawLineEx({offset_x, (float)i * cell_size + offset_y},
                       {offset_x + (float)cols * cell_size, offset_y + (float)i * cell_size},
                       thickness_horizontal, border_horizontal_color);
        }

    if (thickness_vertical)
        for (int i = 0; i <= cols; i++)
        {
            DrawLineEx({offset_x + (float)i * cell_size, offset_y},
                       {offset_x + (float)i * cell_size, offset_y + (float)rows * cell_size},
                       thickness_vertical, border_vertical_color);
        }
}

Grid::Grid()
    : rows(0), cols(0), cell_size(0), cell_color(WHITE), hover_color(GREEN),
      border_horizontal_color(BLACK), border_vertical_color(BLACK), thickness_horizontal(2),
      thickness_vertical(1)
{
}

GridBuilder &GridBuilder::rows(int r)
{
    grid.rows = r;
    return *this;
}

GridBuilder &GridBuilder::cols(int c)
{
    grid.cols = c;
    return *this;
}

GridBuilder &GridBuilder::cell_size(int sz)
{
    grid.cell_size = sz;
    return *this;
}

GridBuilder &GridBuilder::cell_color(Color col)
{
    grid.cell_color = col;
    return *this;
}

GridBuilder &GridBuilder::hover_color(Color col)
{
    grid.hover_color = col;
    return *this;
}

GridBuilder &GridBuilder::border_horizontal_color(Color col)
{
    grid.border_horizontal_color = col;
    return *this;
}

GridBuilder &GridBuilder::border_vertical_color(Color col)
{
    grid.border_vertical_color = col;
    return *this;
}

GridBuilder &GridBuilder::thickness_horizontal(float thickness)
{
    grid.thickness_horizontal = thickness;
    return *this;
}

GridBuilder &GridBuilder::thickness_vertical(float thickness)
{
    grid.thickness_vertical = thickness;
    return *this;
}

Grid GridBuilder::build() { return grid; }