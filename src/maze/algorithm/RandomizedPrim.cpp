//============================================================================
// Name        : RandomizedPrim.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <maze/algorithm/RandomizedPrim.h>

#include <set>

std::unique_ptr<Maze> RandomizedPrim::generate(uint16_t height, uint16_t width,
		bool showConstruction, const Coordinates &startingCell,
		std::shared_ptr<Room> cellValue, const uint32_t seed) {

	auto maze = std::make_unique<Maze>(height, width, cellValue);
	std::mt19937 mt(seed);  // Random generator - Mersenne Twister algorithm

	std::set<std::shared_ptr<MazeCell>> pathSet; // Keep track of possible paths to expand

	// While there is cell within the set:
	pathSet.insert(maze->getCell(startingCell.col, startingCell.row));
	while (!pathSet.empty()) {
		auto cellIt = pathSet.begin();
		std::advance(cellIt, mt() % pathSet.size());
		auto cell = *cellIt;
		cell->setVisited(true);

		// Randomly connect it to a cell that is already part of the maze
		auto neighbours = getNeighbours(*maze, cell->getCoordinates(), true);

		if (!neighbours.empty()) {
			auto randIdx = mt() % neighbours.size();
			maze->connect(cell, neighbours[randIdx]);
		}

		// Add available neighbours and remove current cell
		neighbours = getNeighbours(*maze, cell->getCoordinates(), false);
		pathSet.insert(neighbours.begin(), neighbours.end());
		pathSet.erase(cellIt);

		printWhileConstructing(*maze, showConstruction);
	}

	return maze;
}

std::vector<std::shared_ptr<MazeCell>> RandomizedPrim::getNeighbours(Maze &maze,
		Coordinates coordinates, bool in) {
	std::vector<std::shared_ptr<MazeCell>> neighbours;
	uint16_t row = coordinates.row;
	uint16_t col = coordinates.col;

	if (row - 1 >= 0 && maze(row - 1, col)->isVisited() == in) {
		neighbours.push_back(maze(row - 1, col));
	}

	if (row + 1 < maze.getHeight() && maze(row + 1, col)->isVisited() == in) {
		neighbours.push_back(maze(row + 1, col));
	}

	if (col - 1 >= 0 && maze(row, col - 1)->isVisited() == in) {
		neighbours.push_back(maze(row, col - 1));
	}

	if (col + 1 < maze.getWidth() && maze(row, col + 1)->isVisited() == in) {
		neighbours.push_back(maze(row, col + 1));
	}

	return neighbours;
}
