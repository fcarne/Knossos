//============================================================================
// Name        : Enemy.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================

#include "Enemy.h"

void Enemy::attack(std::shared_ptr<Entity> entity) {
	entity->defend(damage);
}
