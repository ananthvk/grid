#include "grid.hpp"
#include "raylib.h"

const int rows = 100;
const int cols = 100;

// 0 - Dead
// 1 - Alive

std::vector<int> create_state()
{
    std::vector<int> cells;
    cells.resize(rows * cols, 0);
    return cells;
}

void apply_transformation(std::vector<int> &state, std::vector<int> &new_state)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            // Process all surrounding cells
            int num_alive = 0;
            for (int i = -1; i <= 1; i += 1)
            {
                for (int j = -1; j <= 1; j += 1)
                {
                    if (i == 0 && j == 0)
                        continue;
                    int row = r + i;
                    int col = c + j;
                    if (row >= 0 && row < rows && col >= 0 && col < cols)
                    {
                        num_alive += state[row * rows + col];
                    }
                }
            }
            if (state[r * rows + c])
            {
                if (num_alive < 2)
                    new_state[r * rows + c] = 0;
                if (num_alive == 2 || num_alive == 3)
                    new_state[r * rows + c] = 1;
                if (num_alive > 3)
                    new_state[r * rows + c] = 0;
            }
            else
            {
                if (num_alive == 3)
                    new_state[r * rows + c] = 1;
            }
        }
    }
}

auto state = create_state(), new_state = create_state();

void set_cell(const int &row, const int &col) { state[row * rows + col] = 1; }

void erase_cell(const int &row, const int &col) { state[row * rows + col] = 0; }

int main()
{

    InitWindow(800, 800, "Window");
    SetTargetFPS(60);

    // Advance the simulation after the specified seconds
    float update_every = 0.5;
    bool paused = false;

    state[320] = 1;
    state[321] = 1;
    state[322] = 1;

    float accumulator = 0;

    Grid grid = GridBuilder()
                    .rows(rows)
                    .cols(cols)
                    .cell_color(WHITE)
                    .border_horizontal_color(GRAY)
                    .border_vertical_color(GRAY)
                    .thickness_horizontal(1)
                    .thickness_vertical(1)
                    .hover_color(BLACK)
                    .build();

    grid.onclick_left(set_cell);
    grid.onclick_right(erase_cell);

    while (!WindowShouldClose())
    {
        if (!paused)
            accumulator += GetFrameTime();

        if (IsKeyPressed(KEY_F11))
            ToggleFullscreen();
        if (IsKeyDown(KEY_UP))
            update_every += 0.005;
        if (IsKeyDown(KEY_DOWN))
            update_every -= 0.005;
        if (IsKeyPressed(KEY_SPACE))
            paused = !paused;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        grid.render();
        for (int i = 0; i < rows * cols; i++)
            grid.set_color(i / rows, i % rows, state[i] ? BLACK : WHITE);
        EndDrawing();

        if (accumulator >= update_every)
        {
            accumulator = 0;
            apply_transformation(state, new_state);
            state = new_state;
        }
    }
    CloseWindow();
    return 0;
}