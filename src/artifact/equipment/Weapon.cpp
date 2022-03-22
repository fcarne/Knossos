//============================================================================
// Name        : Weapon.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#include <artifact/equipment/Weapon.h>

#include <memory>

#include <entity/Hero.h>

Weapon::Weapon(std::string name, std::string description, uint16_t damage) :
		Artifact(name, description, false, [this](std::shared_ptr<Hero> hero) {
			hero->equipWeapon(shared_from_this());
		}), damage(damage) {
}

uint16_t Weapon::getDamage() {
	return damage;
}

void Weapon::setDamage(uint16_t damage) {
	this->damage = damage;
}

std::string Weapon::toString() {
	return Artifact::toString() + "\n" + "Damage: " + std::to_string(damage);
}
