//============================================================================
// Name        : Trap.cpp
// Author      : Federico Carne 1059865
// Date		   : 25 feb 2022
// Description : 
//============================================================================
#include <artifact/Trap.h>

Trap::Trap(std::string name, std::string description, uint8_t damage,
		std::function<void(std::shared_ptr<Hero>)> effect) :
		Artifact(name, description, true, effect), damage(damage) {
}

uint8_t Trap::getDamage() {
	return damage;
}

std::string Trap::toString() {
	return Artifact::toString() + "\n" + "Damage: " + std::to_string(unsigned(damage));
}

