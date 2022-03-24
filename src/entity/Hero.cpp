//============================================================================
// Name        : Hero.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <entity/Hero.h>

Hero::Hero(std::string name, int16_t hp, uint16_t damage,
		std::shared_ptr<MazeCell> cell, std::string sprite) :
		Entity(hp, damage, cell, Alignment::NEUTRAL, sprite), name(name) {
}

uint16_t Hero::attack(std::shared_ptr<Enemy> enemy) {
	uint16_t attackPower = damage
			+ (weapon != nullptr ? weapon->getDamage() : 0);
	std::uniform_real_distribution<> dis(0.9, 1.2);
	attackPower *= dis(mt);
	enemy->defend(attackPower);

	return attackPower;
}

uint16_t Hero::defend(uint16_t damage) {
	uint16_t defense = (armor != nullptr ? armor->getDefense() : 0);
	uint16_t damageReceived = damage / ((defense + 100) / 100);
	hp -= damageReceived;

	return damageReceived;
}

bool Hero::move(Direction d) {
	if (currentCell->hasNeighbourInDirection(d)) {
		currentCell->getContent()->setHero(nullptr);
		currentCell = currentCell->getNeighbour(d);
		currentCell->getContent()->setHero(shared_from_this());
		return true;
	} else
		return false;
}

std::string Hero::getName() const {
	return name;
}

void Hero::equipWeapon(std::shared_ptr<Weapon> weapon) {
	this->weapon = weapon;
}
void Hero::equipArmor(std::shared_ptr<Armor> armor) {
	this->armor = armor;
}

void Hero::unequipWeapon() {
	weapon = nullptr;
}
void Hero::unequipArmor() {
	armor = nullptr;
}

std::shared_ptr<Weapon> Hero::getWeapon() const {
	return weapon;
}
std::shared_ptr<Armor> Hero::getArmor() const {
	return armor;
}
