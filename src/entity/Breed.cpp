//============================================================================
// Name        : Breed.cpp
// Author      : Federico Carne 1059865
// Date		   : 9 mar 2022
// Description : 
//============================================================================
#include <entity/Breed.h>

#include <entity/Enemy.h>
Breed::Breed(uint16_t maxHp, uint16_t damage, std::string attackString,
		std::string breedName, MovePattern movePattern, std::string tile) :
		maxHp(maxHp), damage(damage), attackString(attackString), breedName(
				breedName), movePattern(movePattern), tile(tile) {
}

std::shared_ptr<Enemy> Breed::newEnemy(std::shared_ptr<MazeCell> cell) {
	return std::shared_ptr<Enemy>(new Enemy(*this, cell));
}

uint16_t Breed::getMaxHp() {
	return maxHp;
}

uint16_t Breed::getDamage() {
	return damage;
}

std::string Breed::getAttackString() const {
	return attackString;
}

std::string Breed::getBreedName() const {
	return breedName;
}

MovePattern& Breed::getMovePattern() {
	return movePattern;
}

std::string Breed::getTile() const {
	return tile;
}
