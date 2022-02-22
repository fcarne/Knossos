//============================================================================
// Name        : SideWinder.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_ALGORITHM_SIDEWINDER_H_
#define MAZE_ALGORITHM_SIDEWINDER_H_

#include <maze/MazeAlgorithm.h>

class SideWinder: public MazeAlgorithm {
public:
	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			const Point &startingCell, const Room &cellValue,
			const uint32_t seed) override;
};

#endif /* MAZE_ALGORITHM_SIDEWINDER_H_ */
