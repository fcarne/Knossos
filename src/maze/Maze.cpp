//============================================================================
// Name        : Maze.cpp
// Author      : Federico Carne 1059865
// Date		   : 19 feb 2022
// Description : 
//============================================================================

#include <iostream>

#include <maze/Maze.h>

void Maze::print() {
	for (uint16_t j = 0; j < getWidth() * 2 + 1; ++j)
		std::cout << "██";
	std::cout << "\n";

	for (uint16_t i = 0; i < getHeight(); ++i) {
		std::cout << "██";
		for (uint16_t j = 0; j < getWidth(); ++j) {
			auto cell = getCell(i, j);
			std::cout << "  "
					<< (cell->hasNeighbourInDirection(Direction::E) ?
							"  " : "██");
		}
		std::cout << "\n" << "██";
		for (uint16_t j = 0; j < getWidth(); ++j) {
			auto cell = getCell(i, j);
			std::cout
					<< (cell->hasNeighbourInDirection(Direction::S) ?
							"  " : "██") << "██";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

bool Maze::checkWinningMove(Coordinates &c, Direction d) {
	return winningRoom == c && winningDirection == d;
}

void Maze::setWinningMove(Coordinates c, Direction d) {
	winningRoom = c;
	winningDirection = d;
}
