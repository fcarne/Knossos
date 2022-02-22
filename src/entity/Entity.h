//============================================================================
// Name        : Entity.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : Entity and subclasses definition
//============================================================================
#ifndef ENTITY_ENTITY_H_
#define ENTITY_ENTITY_H_

#include <cstdint>
#include <functional>
#include <string>

#include <maze/Maze.h>

class Entity {
protected:
	int16_t hp;
	int16_t damage;
	std::shared_ptr<MazeCell> currentCell;
private:
	std::string name;
	std::string type;
public:
	Entity(int16_t hp, int16_t damage, std::shared_ptr<MazeCell> cell,
			std::string name, std::string type);
	int16_t getHp();
	int16_t getDamage();
	std::string getName() const;
	std::string getType() const;
	std::shared_ptr<MazeCell> getCell();

	void defend(int16_t damage);
};

#endif /* ENTITY_ENTITY_H_ */
