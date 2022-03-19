//============================================================================
// Name        : Enemy.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_ENEMY_H_
#define ENTITY_ENEMY_H_

#include <string>
#include <random>
#include <memory.h>

#include <entity/Entity.h>
#include <entity/Breed.h>

class Enemy: public Entity, private Breed, public std::enable_shared_from_this<Enemy> {
	friend class Breed;

private:
	Enemy(Breed&, std::shared_ptr<MazeCell> cell);

public:
	using Entity::damage;
	using Entity::getDamage;
	using Breed::getBreedName;
	using Breed::getAttackString;
	using Entity::getTile;

	virtual uint16_t attack(std::shared_ptr<Entity>);
	virtual std::shared_ptr<MazeCell> move();
};

#endif /* ENTITY_ENEMY_H_ */
