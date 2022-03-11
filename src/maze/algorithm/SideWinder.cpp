//============================================================================
// Name        : SideWinder.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <maze/algorithm/SideWinder.h>

#include <set>

std::unique_ptr<Maze> SideWinder::generate(uint16_t height, uint16_t width,
		bool showConstruction, const Coordinates &startingCell,
		const Room &cellValue, const uint32_t seed) {
	if (width < 1 || height < 1)
		return nullptr;

	auto maze = std::make_unique<Maze>(height, width, cellValue);
	std::mt19937 mt(seed); // Random generator based on Mersenne Twister algorithm
	std::set<std::shared_ptr<MazeCell>> runSet; // Keep track of possible paths to expand

	// Initialize an empty “run” set to keep track of the current line path.
	// Scan grid line by line starting with the cell[0,0]:
	for (uint16_t row = 0; row < height; ++row) {
		for (uint16_t col = 0; col < width; ++col) {
			// Add current cell to the path (avoid useless insertion)
			if (row > 0)
				runSet.insert((*maze)(row, col));

			if (col + 1 < width && (mt() % 2 == 0 || row == 0)) {
				// Randomly carve to east or north
				// If a passage was carved, continue line scan.
				// First row can only be a single passage, crave it to the east
				auto c1 = (*maze)(row, col);
				auto c2 = (*maze)(row, col + 1);
				maze->connect(c1, c2);
			} else if (row > 0) {
				// Otherwise randomly choose a cell in the run set and carve north
				auto cellIt = runSet.begin();
				std::advance(cellIt, mt() % runSet.size());

				auto c1 = *cellIt;
				auto c2 = (*maze)(c1->getRow() - 1, c1->getCol());
				maze->connect(c1, c2);
				runSet.clear(); // Empty the run set and continue line scan
			}

			printWhileConstructing(*maze, showConstruction);
		}

		runSet.clear();
	}

	return maze;
}

