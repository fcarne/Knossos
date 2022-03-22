//============================================================================
// Name        : Entity.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : Entity and subclasses definition
//============================================================================
#ifndef ENTITY_ENTITY_H_
#define ENTITY_ENTITY_H_

#include <cstdint>
#include <random>
#include <memory>
#include <string>

#include <maze/Maze.h>

class Entity {
public:
	enum class Alignment : uint8_t {
		NEUTRAL, AGGRESSIVE, FRIENDLY
	};
protected:
	int16_t hp;
	uint16_t damage;
	std::shared_ptr<MazeCell> currentCell;
	Alignment alignment;
	std::string sprite;
	std::mt19937 mt;
public:
	Entity(int16_t hp, uint16_t damage, std::shared_ptr<MazeCell> cell,
			Alignment alignment, std::string sprite);
	virtual ~Entity() = default;

	int16_t getHp();
	uint16_t getDamage();
	std::shared_ptr<MazeCell> getCell();
	Alignment getAlignment();
	std::string getSprite() const;

	virtual uint16_t defend(uint16_t damage);
};

#endif /* ENTITY_ENTITY_H_ */
