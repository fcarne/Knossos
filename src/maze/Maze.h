//============================================================================
// Name        : Maze.h
// Author      : Federico Carne 1059865
// Date		   : 19 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_MAZE_H_
#define MAZE_MAZE_H_

#include <grid/Grid.h>
#include <maze/room/Room.h>
#include <grid/Coordinates.h>
#include <grid/Direction.h>

typedef GridCell<Room> MazeCell;

class Maze: public Grid<Room> {
private:
	Coordinates winningRoom;
	Direction winningDirection;
public:
	using Grid<Room>::Grid;

	void print();
	bool checkWinningMove(Coordinates& c, Direction d);
	void setWinningMove(Coordinates c, Direction d);
};

#endif /* MAZE_MAZE_H_ */
