//============================================================================
// Name        : GameMode.h
// Author      : Federico Carne 1059865
// Date		   : 13 mar 2022
// Description : 
//============================================================================
#ifndef GAME_GAMEMODE_H_
#define GAME_GAMEMODE_H_

#include <memory>
#include <random>
#include <string>
#include <tuple>

#include <maze/Maze.h>
#include <entity/Hero.h>
#include <maze/room/Room.h>

class GameMode {
protected:
	static const char UP_KEY;
	static const char DOWN_KEY;
	static const char LEFT_KEY;
	static const char RIGHT_KEY;
	static const char HELP_KEY;
	static const char EXIT_KEY;

	std::unique_ptr<Maze> maze;
	Coordinates startingCoords;
	std::shared_ptr<Hero> hero;
	std::mt19937 mt;

	Room room;

	GameMode(Room);
	bool checkArtifact(std::shared_ptr<Room>);
	bool retry();
	void saveMaze();
	virtual void printHelp();
	std::pair<Direction, bool> readUserInput();
public:
	virtual ~GameMode() = default;
	virtual void initGame();
	virtual void play() = 0;
	virtual void printDescription() = 0;
};

#endif /* GAME_GAMEMODE_H_ */
