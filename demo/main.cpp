#include "grid.hpp"
#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Window");
    SetTargetFPS(60);
    Grid grid = GridBuilder()
                    .sides(8)
                    .thickness_horizontal(1)
                    .thickness_vertical(1)
                    .border_vertical_color(WHITE)
                    .border_horizontal_color(WHITE)
                    .cell_color(BLUE)
                    .hover_color(RED)
                    .centered()
                    .build();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        grid.render();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}