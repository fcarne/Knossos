//============================================================================
// Name        : Hero.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_HERO_H_
#define ENTITY_HERO_H_

#include <memory>
#include <string>

#include <entity/Enemy.h>
#include <artifact/equipment/Weapon.h>
#include <artifact/equipment/Armor.h>

class Hero: public Entity {
private:
	std::string name;
	std::shared_ptr<Weapon> weapon;
	std::shared_ptr<Armor> armor;
public:
	Hero(std::string name, int16_t hp, uint16_t damage,
			std::shared_ptr<MazeCell> cell, std::string tile);
	uint16_t attack(std::shared_ptr<Enemy>);
	uint16_t defend(uint16_t damage) override;
	virtual bool move(Direction);

	void equipWeapon(std::shared_ptr<Weapon>);
	void equipArmor(std::shared_ptr<Armor>);
	void unequipWeapon();
	void unequipArmor();
	std::shared_ptr<Weapon> getWeapon() const;
	std::shared_ptr<Armor> getArmor() const;
};

#endif /* ENTITY_HERO_H_ */
