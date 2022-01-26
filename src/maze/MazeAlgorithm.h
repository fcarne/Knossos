//============================================================================
// Name        : MazeAlgorithm.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : 
//============================================================================
#ifndef MAZE_MAZEALGORITHM_H_
#define MAZE_MAZEALGORITHM_H_

#include <random>
#include <vector>
#include <memory>

#include "../grid/Grid.h"
#include "Room.h"

typedef Grid<Room> Maze;
typedef GridCell<Room> MazeCell;

class MazeAlgorithm {
public:
	virtual ~MazeAlgorithm() = default;
	virtual std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			const Point &startingCell, const Room &cellValue,
			const uint32_t seed) = 0;
};

class PrimAlgorithm: public MazeAlgorithm {
public:
	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			const Point &startingCell, const Room &cellValue,
			const uint32_t seed) override;
private:
	std::vector<std::shared_ptr<MazeCell>> getNeighbours(Maze &maze,
			Point coordinates, bool in);
};

class RecursiveDivision: public MazeAlgorithm {
public:
	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			const Point &startingCell, const Room &cellValue,
			const uint32_t seed) override;
private:
	void divide(Maze &maze, const Point &ref, uint16_t height, uint16_t width,
			std::mt19937 &mt);

	void disconnectRow(Maze &maze, const Point& origin, uint16_t width, uint16_t pathCol);
	void disconnectCol(Maze &maze, const Point& origin, uint16_t height, uint16_t pathRow);
};

#endif /* MAZE_MAZEALGORITHM_H_ */
