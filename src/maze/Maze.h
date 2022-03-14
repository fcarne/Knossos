//============================================================================
// Name        : Maze.h
// Author      : Federico Carne 1059865
// Date		   : 19 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_MAZE_H_
#define MAZE_MAZE_H_

#include <grid/Grid.h>
#include <grid/Coordinates.h>
#include <grid/Direction.h>

#include <maze/room/Room.h>

typedef GridCell<Room> MazeCell;

class Maze: public Grid<Room> {
private:
	Coordinates winningRoom;
	Direction winningDirection;
public:
	using Grid<Room>::Grid;

	void draw(bool drawRooms = false);
	bool checkWinningMove(std::shared_ptr<MazeCell> current, Direction d);
	void setWinningMove(std::shared_ptr<MazeCell> startingRoom, uint32_t seed = 0);

	friend std::ostream& operator<<(std::ostream &outs, Maze &m);
};

#endif /* MAZE_MAZE_H_ */
