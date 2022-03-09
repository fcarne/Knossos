//============================================================================
// Name        : Hero.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_HERO_H_
#define ENTITY_HERO_H_

#include <memory>

#include <entity/WanderingEntity.h>
#include <entity/Enemy.h>

class Hero: public WanderingEntity {
private:
	uint16_t armorDefense;
	uint16_t weaponAttack;
	uint16_t lastDamage;
	/* conditions */
public:
	Hero(int16_t hp, int16_t damage, std::shared_ptr<MazeCell> cell,
				std::string name, std::string type,
				std::function<void(MazeCell&)> _move);
	void attack(std::shared_ptr<Enemy> enemy);
	virtual void defend(uint16_t damage);
};

#endif /* ENTITY_HERO_H_ */
