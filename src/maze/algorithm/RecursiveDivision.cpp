//============================================================================
// Name        : RecursiveDivision.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <maze/algorithm/RecursiveDivision.h>

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

	maze.print();
	system("pause");

	// Build a wall within the room, whether vertical or horizontal,
	// Open a gate at a random position
	bool horizontalCut;
	if (width < height)
		horizontalCut = true;
	else if (width > height)
		horizontalCut = false;
	else
		horizontalCut = (mt() % 2 == 0);

	uint32_t wallIdx = horizontalCut ? mt() % (height - 1) : mt() % (width - 1);
	uint32_t pathIdx = horizontalCut ? mt() % width : mt() % height;

	std::cout << "h or v:" << horizontalCut << " - wall: " << wallIdx << " - path: " << pathIdx << "\n";

	if (horizontalCut) {
		// Top and Bottom
		disconnectHorizontal(maze, Point(ref.col, ref.row + wallIdx), width, pathIdx);
		divide(maze, ref, wallIdx + 1, width, mt);
		divide(maze, Point(ref.col, ref.row + wallIdx + 1), height - wallIdx - 1,
				width, mt);
	} else {
		//Left and Right
		disconnectVertical(maze, Point(ref.col + wallIdx, ref.row), height, pathIdx);
		divide(maze, ref, height, wallIdx + 1, mt);
		divide(maze, Point(ref.col + wallIdx + 1, ref.row), height,
				width - wallIdx - 1, mt);
	}

}

void RecursiveDivision::disconnectHorizontal(Maze &maze, const Point &origin,
		uint16_t width, uint16_t pathCol) {
	if (origin.row >= maze.getHeight() - 1 || origin.col >= maze.getWidth())
		return;

	Direction d = Direction::S;
	uint16_t w = std::min((int) width, maze.getWidth() - origin.col);
	for (uint16_t col = 0; col < w; ++col) {
		if (col == pathCol)
			continue;
		maze.disconnect(maze(origin.row, origin.col + col), d);
	}
}

void RecursiveDivision::disconnectVertical(Maze &maze, const Point &origin,
		uint16_t height, uint16_t pathRow) {
	if (origin.col >= maze.getWidth() - 1 || origin.row >= maze.getHeight())
		return;

	Direction d = Direction::E;
	uint16_t w = std::min((int) height, maze.getHeight() - origin.row);
	for (uint16_t row = 0; row < w; ++row) {
		if (row == pathRow)
			continue;
		maze.disconnect(maze(origin.row + row, origin.col), d);
	}
}
