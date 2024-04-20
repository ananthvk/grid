#include "grid/include/grid.hpp"
#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Window");
    SetTargetFPS(60);
    Grid grid;
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