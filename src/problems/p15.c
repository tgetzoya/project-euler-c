#include "problems.h"

void calculate_at_position (uint_fast64_t grid[GRID_21x21][GRID_21x21], uint_fast8_t x, uint_fast8_t y);

Response* p15(void) {
    const uint_fast64_t EXPECTED = 137846528820;

    uint_fast64_t grid[GRID_21x21][GRID_21x21] = {0};

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    calculate_at_position(grid, 0, 0);
    uint_fast64_t number_of_routes = grid[0][0];

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(number_of_routes, EXPECTED, number_of_routes == EXPECTED, start, end);
}

void calculate_at_position (uint_fast64_t grid[GRID_21x21][GRID_21x21], uint_fast8_t x, uint_fast8_t y) {
    uint_fast64_t routes = 0;

    if (grid[x][y] != 0) {
        return;
    }

    if (x == (GRID_21x21 - 1) && (y == GRID_21x21 - 1)) {
        grid[x][y] = 1;
        return;
    }

    if (x + 1 < GRID_21x21) {
        if (grid[x+1][y] == 0) {
            calculate_at_position(grid, x + 1, y);
        }

        routes += grid[x+1][y];
    }

    if (y + 1 < GRID_21x21) {
        if (grid[x][y+1] == 0) {
            calculate_at_position(grid, x, y + 1);
        }

        routes += grid[x][y+1];
    }

    grid[x][y] = routes;
}
