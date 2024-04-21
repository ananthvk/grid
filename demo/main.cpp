#include "grid.hpp"
#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Window");
    SetTargetFPS(60);
    Grid grid = GridBuilder()
                    .rows(100)
                    .cols(100)
                    .cell_color(BLUE)
                    .hover_color(DARKBLUE)
                    .build();
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
            ToggleFullscreen();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        grid.render();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}