//============================================================================
// Name        : Grid_test.cpp
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : MazeGenerator test
//============================================================================

#include <iostream>
#include <memory>

#include "../src/maze/MazeGenerator.h"

bool hasN(MazeCell c, Direction d) {
	auto n = c.getNeighbours();
	return !(n.find(d) == n.end());
}

void printMaze(Maze maze) {
	std::cout << maze.getHeight() << " ROWS, " << maze.getWidth()
				<< " COLUMNS!\n";
	for (uint16_t i = 0; i < maze.getHeight(); i++) {
		for (uint16_t j = 0; j < maze.getWidth(); j++) {
			std::cout << "+" << (hasN(*maze(i, j), Direction::N) ? " " : "-")
					<< "+";
		}
		std::cout << "\n";
		for (uint16_t j = 0; j < maze.getWidth(); j++) {
			std::cout << (hasN(*maze(i, j), Direction::W) ? " " : "|") << " "
					<< (hasN(*maze(i, j), Direction::E) ? " " : "|");
		}
		std::cout << "\n";
		for (uint16_t j = 0; j < maze.getWidth(); j++) {
			std::cout << "+" << (hasN(*maze(i, j), Direction::S) ? " " : "-")
					<< "+";
		}
		std::cout << "\n";
	}
}

int main() {
	std::unique_ptr<MazeAlgorithm> algorithm;
	algorithm = std::make_unique<RecursiveDivision>();
	MazeGenerator generator(algorithm);
	std::unique_ptr<Maze> maze = generator.generate(12, 12, Point(0,0), Room(), 0);

	std::cout << maze->getHeight() << " ROWS, " << maze->getWidth()
			<< " COLUMNS!\n";
	for (int row = 0; row < maze->getHeight(); ++row) {
		for (int col = 0; col < maze->getWidth(); ++col) {
			std::cout << *(*maze)(row, col) << " --- ";
		}
		std::cout << "\n";
	}

	generator.print(maze);
	return 0;
}

