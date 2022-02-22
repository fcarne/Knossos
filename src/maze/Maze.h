//============================================================================
// Name        : Maze.h
// Author      : Federico Carne 1059865
// Date		   : 19 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_MAZE_H_
#define MAZE_MAZE_H_

#include <grid/Grid.h>
#include "room/Room.h"

typedef GridCell<Room> MazeCell;

class Maze: public Grid<Room> {
public:
	using Grid<Room>::Grid;

	void print();
};

#endif /* MAZE_MAZE_H_ */
