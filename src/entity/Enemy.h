//============================================================================
// Name        : Enemy.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_ENEMY_H_
#define ENTITY_ENEMY_H_

#include <entity/Entity.h>
#include <entity/WanderingEntity.h>

class Enemy: virtual public Entity {
public:
	using Entity::Entity;
	virtual void attack(std::shared_ptr<Entity>);
};

class WanderingEnemy: public Enemy, public WanderingEntity {
public:
	using WanderingEntity::WanderingEntity;
};

#endif /* ENTITY_ENEMY_H_ */
