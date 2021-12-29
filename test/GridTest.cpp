#include <iostream>

#include "./../src/maze/Grid.h"
int main(int argc, char const *argv[]) {
    Grid<int> grid(5, 5, 2);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

    return 0;
}