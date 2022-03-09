//============================================================================
// Name        : Entity.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================

#include <entity/Entity.h>

Entity::Entity(int16_t hp, int16_t damage, std::shared_ptr<MazeCell> cell,
		std::string name, std::string type) :
		hp(hp), damage(damage), currentCell(cell), name(name), type(type) {
}
int16_t Entity::getHp() {
	return hp;
}
int16_t Entity::getDamage() {
	return damage;
}
std::string Entity::getName() const {
	return name;
}
std::string Entity::getType() const {
	return type;
}
std::shared_ptr<MazeCell> Entity::getCell() {
	return currentCell;
}

void Entity::defend(int16_t damage) {
	hp -= damage;
}
