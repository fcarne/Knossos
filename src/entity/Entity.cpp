//============================================================================
// Name        : Entity.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================

#include <entity/Entity.h>

Entity::Entity(int16_t hp, uint16_t damage, std::shared_ptr<MazeCell> cell, Alignment alignment, std::string sprite) :
		hp(hp), damage(damage), currentCell(cell), alignment(alignment),  sprite(sprite) {
	uint32_t a = (uint32_t) hp;
		uint32_t b = (uint32_t) damage;
		uint32_t seed  = (a >= b) ? a * a + a + b : a + b * b;
		mt = std::mt19937(seed);
}

int16_t Entity::getHp() {
	return hp;
}

uint16_t Entity::getDamage() {
	return damage;
}

std::shared_ptr<MazeCell> Entity::getCell() {
	return currentCell;
}

Entity::Alignment Entity::getAlignment() {
	return alignment;
}

std::string Entity::getSprite() const {
	return sprite;
}

uint16_t Entity::defend(uint16_t damage) {
	hp -= damage;
	return damage;
}
