//============================================================================
// Name        : RandomizedPrim.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_ALGORITHM_RANDOMIZEDPRIM_H_
#define MAZE_ALGORITHM_RANDOMIZEDPRIM_H_

#include <maze/MazeAlgorithm.h>

class RandomizedPrim: public MazeAlgorithm {
public:
	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			bool showConstruction, const Coordinates &startingCell,
			std::shared_ptr<Room> cellValue, const uint32_t seed) override;
private:
	std::vector<std::shared_ptr<MazeCell>> getNeighbours(Maze &maze,
			Coordinates coordinates, bool in);
};

#endif /* MAZE_ALGORITHM_RANDOMIZEDPRIM_H_ */
