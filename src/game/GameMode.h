//============================================================================
// Name        : GameMode.h
// Author      : Federico Carne 1059865
// Date		   : 13 mar 2022
// Description : 
//============================================================================
#ifndef GAME_GAMEMODE_H_
#define GAME_GAMEMODE_H_

#include <memory>

#include <maze/Maze.h>

class GameMode {
protected:
	std::unique_ptr<Maze> maze;
public:
	void start();
	void gameOver();
	void playerMove();
	void win();
};

#endif /* GAME_GAMEMODE_H_ */
