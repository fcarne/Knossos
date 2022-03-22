//============================================================================
// Name        : Breed.cpp
// Author      : Federico Carne 1059865
// Date		   : 9 mar 2022
// Description : 
//============================================================================
#include <entity/Breed.h>

#include <entity/Enemy.h>
Breed::Breed(uint16_t maxHp, uint16_t damage, std::string attackString,
		std::string breedName, uint16_t breedPopulation,
		MovePattern movePattern, std::string sprite) :
		maxHp(maxHp), damage(damage), attackString(attackString), breedName(
				breedName), breedPopulation(breedPopulation), movePattern(
				movePattern), sprite(sprite) {
}

std::shared_ptr<Enemy> Breed::newEnemy(std::shared_ptr<MazeCell> cell) {
	return breedPopulation-- > 0 ?
			std::shared_ptr<Enemy>(new Enemy(*this, cell)) : nullptr;
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

uint16_t Breed::getBreedPopulation() {
	return breedPopulation;
}

MovePattern& Breed::getMovePattern() {
	return movePattern;
}

std::string Breed::getSprite() const {
	return sprite;
}
