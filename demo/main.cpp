#include "grid.hpp"
#include "raylib.h"

int main()
{
    InitWindow(1920, 1080, "Window");
    ToggleFullscreen();
    SetTargetFPS(60);
    Grid grid = GridBuilder()
                    .rows(108)
                    .cols(192)
                    .cell_size(40)
                    .thickness_horizontal(20)
                    .thickness_vertical(20)
                    .border_vertical_color(WHITE)
                    .border_horizontal_color(WHITE)
                    .cell_color(BLUE)
                    .hover_color(RED)
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