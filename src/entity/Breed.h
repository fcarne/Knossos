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
	uint16_t tilesNumber;
	uint16_t sleepTurns;
};

class Breed {
private:
	uint16_t maxHp;
	uint16_t damage;
	std::string attackString;
	std::string breedName;
	uint16_t breedPopulation;
	MovePattern movePattern;
	std::string sprite;
public:
	Breed(uint16_t maxHp, uint16_t damage, std::string attackString,
			std::string breedName, uint16_t breedPopulation,
			MovePattern movePattern, std::string sprite);
	std::shared_ptr<Enemy> newEnemy(std::shared_ptr<MazeCell> cell);

	uint16_t getMaxHp();
	uint16_t getDamage();
	std::string getAttackString() const;
	std::string getBreedName() const;
	uint16_t getBreedPopulation();
	MovePattern& getMovePattern();
	std::string getSprite() const;
};

#endif /* ENTITY_BREED_H_ */
