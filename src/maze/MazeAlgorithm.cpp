//============================================================================
// Name        : MazeAlgorithm.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : 
//============================================================================

#include <set>
#include <iostream>
#include "MazeAlgorithm.h"

std::unique_ptr<Maze> PrimAlgorithm::generate(uint16_t height, uint16_t width,
		const Point &startingCell, const Room &cellValue, const uint32_t seed) {

	auto maze = std::make_unique<Maze>(height, width, cellValue);
	std::mt19937 mt(seed);  // Random generator - Mersenne Twister algorithm

	std::set<std::shared_ptr<MazeCell>> pathSet; // Keep track of possible paths to expand

	// While there is cell within the set:
	pathSet.insert(maze->getCell(startingCell.x, startingCell.y));
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
	}

	return maze;
}

std::vector<std::shared_ptr<MazeCell>> PrimAlgorithm::getNeighbours(Maze &maze,
		Point coordinates, bool in) {
	std::vector<std::shared_ptr<MazeCell>> neighbours;
	uint16_t row = coordinates.y;
	uint16_t col = coordinates.x;

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

std::unique_ptr<Maze> RecursiveDivision::generate(uint16_t height,
		uint16_t width, const Point &startingCell, const Room &cellValue,
		const uint32_t seed) {
	auto maze = std::make_unique<Maze>(height, width, cellValue, true);
	std::mt19937 mt(seed);  // Initialize random generator (Mersenne Twister)

	divide(*maze, Point(0, 0), height, width, mt);

	return maze;
}

void RecursiveDivision::divide(Maze &maze, const Point &ref, uint16_t height,
		uint16_t width, std::mt19937 &mt) {
	if (width < 2 || height < 2)
		return;

	// Build a wall within the room, whether vertical or horizontal,
	// Open a gate at a random position
	bool horizontalCut;
	if(width<height) horizontalCut = true;
	else if(width > height) horizontalCut = false;
	else horizontalCut = (mt() % 2 == 0);

	uint32_t wallIdx = horizontalCut ? mt() % (height - 1) : mt() % (width - 1);
	uint32_t pathIdx = horizontalCut ? mt() % width : mt() % height;

	if (horizontalCut) {
		// Top and Bottom
		disconnectRow(maze, Point(ref.x, ref.y + wallIdx), width, pathIdx);
		divide(maze, ref, wallIdx + 1, width, mt);
		divide(maze, Point(ref.x, ref.y + wallIdx + 1), height - wallIdx - 1,
				width, mt);
	} else {
		//Left and Right
		disconnectCol(maze, Point(ref.x + wallIdx, ref.y), height, pathIdx);
		divide(maze, ref, height, wallIdx + 1, mt);
		divide(maze, Point(ref.x + wallIdx + 1, ref.y), height,
				width - wallIdx - 1, mt);
	}
}

void RecursiveDivision::disconnectRow(Maze &maze, const Point& origin, uint16_t width, uint16_t pathCol) {
	if(origin.y >= maze.getHeight() -1 || origin.x >= maze.getWidth()) return;

	Direction d = Direction::S;
	uint16_t w = std::min((int) width, maze.getWidth() - origin.x);
	for(uint16_t col = 0; col < w; ++col) {
		if(col == pathCol) continue;
		maze.disconnect(maze(origin.x + col, origin.y), d);
	}
}

void RecursiveDivision::disconnectCol(Maze &maze, const Point& origin, uint16_t height, uint16_t pathRow) {
	if(origin.x >= maze.getWidth() -1 || origin.y >= maze.getHeight()) return;

	Direction d = Direction::E;
	uint16_t w = std::min((int) height, maze.getHeight() - origin.y);
	for(uint16_t row = 0; row < w; ++row) {
		if(row == pathRow) continue;
		maze.disconnect(maze(origin.x, origin.y + row), d);
	}
}
