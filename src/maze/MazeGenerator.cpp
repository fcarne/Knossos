//============================================================================
// Name        : MazeGenerator.cpp
// Author      : Federico Carne 1059865
// Date		   : 25 gen 2022
// Description : MazeGenerator implementation
//============================================================================

#include <set>
#include <algorithm>
#include <iostream>

#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(std::unique_ptr<MazeAlgorithm> &alg) {
	setAlgorithm(alg);
}

std::unique_ptr<Maze> MazeGenerator::generate(uint16_t height, uint16_t width,
		const Point &startingCell, const Room &cellValue, const uint32_t seed) {
	if (width < 1 || height < 1)
		return nullptr;

	return algorithm->generate(height, width, startingCell, cellValue, seed);
}

void MazeGenerator::setAlgorithm(std::unique_ptr<MazeAlgorithm> &alg) {
	algorithm = std::move(alg);
}

void MazeGenerator::print(std::unique_ptr<Maze> &maze) {
	for (uint16_t j = 0; j < maze->getWidth() * 2 + 1; ++j)
		std::cout << "#";
	std::cout << "\n";

	for (uint16_t i = 0; i < maze->getHeight(); ++i) {
		std::cout << "#";
		for (uint16_t j = 0; j < maze->getWidth(); ++j) {
			auto cell = maze->getCell(i, j);
			std::cout << " "
					<< (cell->hasNeighbourInDirection(Direction::E) ? " " : "#");
		}
		std::cout << "\n" << "#";
		for (uint16_t j = 0; j < maze->getWidth(); ++j) {
			auto cell = maze->getCell(i, j);
			std::cout
					<< (cell->hasNeighbourInDirection(Direction::S) ? " " : "#")
					<< "#";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
