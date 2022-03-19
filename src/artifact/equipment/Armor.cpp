//============================================================================
// Name        : Armor.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#include <artifact/equipment/Armor.h>

#include <memory>

#include <entity/Hero.h>

Armor::Armor(std::string name, std::string description, uint16_t defense) :
		Artifact(name, description, false, [this](std::shared_ptr<Hero> hero) {
			hero->equipArmor(shared_from_this());
		}), defense(defense) {
}

uint16_t Armor::getDefense() {
	return defense;
}

void Armor::setDefense(uint16_t defense) {
	this->defense = defense;
}
