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
#include <vector>

#include <maze/Maze.h>
#include <entity/Hero.h>
#include <maze/room/Room.h>

class GameMode {
protected:
	static const char UP_KEY = 'w';
	static const char DOWN_KEY = 's';
	static const char LEFT_KEY = 'a';
	static const char RIGHT_KEY = 'd';
	static const char HELP_KEY = 'q';
	static const char EXIT_KEY = 'e';

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
	bool setArtifact(std::shared_ptr<Artifact> artifact,
			std::vector<Coordinates> prohibited,
			std::uniform_int_distribution<> rowRange,
			std::uniform_int_distribution<> colRange);
public:
	virtual ~GameMode() = default;
	virtual void initGame();
	virtual void play() = 0;
	virtual void printDescription() = 0;
};

#endif /* GAME_GAMEMODE_H_ */
