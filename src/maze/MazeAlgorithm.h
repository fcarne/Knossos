//============================================================================
// Name        : MazeAlgorithm.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : MazeAlgorithm & concrete algorithms definitions
//============================================================================
#ifndef MAZE_MAZEALGORITHM_H_
#define MAZE_MAZEALGORITHM_H_

#include <random>
#include <vector>
#include <memory>

#include "Maze.h"

class MazeAlgorithm {
public:
	virtual ~MazeAlgorithm() = default;
	virtual std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			const Point &startingCell, const Room &cellValue,
			const uint32_t seed) = 0;
};

#endif /* MAZE_MAZEALGORITHM_H_ */
