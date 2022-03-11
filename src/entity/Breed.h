//============================================================================
// Name        : Breed.h
// Author      : Federico Carne 1059865
// Date		   : 9 mar 2022
// Description : 
//============================================================================
#ifndef ENTITY_BREED_H_
#define ENTITY_BREED_H_

#include <cstdint>
#include <memory>
#include <maze/Maze.h>
#include <string>

class Enemy;

struct MovePattern {
	uint8_t tilesNumber;
	uint8_t sleepTurns;
};

class Breed {
private:
	uint16_t maxHp;
	uint16_t damage;
	std::string attackString;
	std::string breedName;
	MovePattern movePattern;
	std::string tile;
public:
	Breed(uint16_t maxHp, uint16_t damage, std::string attackString,
			std::string breedName, MovePattern movePattern, std::string tile);
	std::shared_ptr<Enemy> newEnemy(std::shared_ptr<MazeCell> cell);
	uint16_t getMaxHp();
	uint16_t getDamage();
	std::string getAttackString() const;
	std::string getBreedName() const;
	MovePattern& getMovePattern();
	std::string getTile() const;
};

#endif /* ENTITY_BREED_H_ */
