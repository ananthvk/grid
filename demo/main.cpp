#include "grid.hpp"
#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Window");
    SetTargetFPS(60);
    Grid grid = GridBuilder()
                    .rows(10)
                    .cols(8)
                    .cell_size(20)
                    .thickness_horizontal(2)
                    .thickness_vertical(3)
                    .build();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        grid.render(100, 30);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}