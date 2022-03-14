//============================================================================
// Name        : Enemy.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================

#include <entity/Enemy.h>

Enemy::Enemy(Breed &breed, std::shared_ptr<MazeCell> cell) :
		Entity(breed.getMaxHp(), breed.getDamage(), cell, Alignment::AGGRESSIVE,
				breed.getTile()), Breed(breed) {
}

uint16_t Enemy::attack(std::shared_ptr<Entity> entity) {
	std::uniform_real_distribution<> dis(0.8, 1.1);
	return entity->defend(damage * (int) dis(mt));
}

std::shared_ptr<MazeCell> Enemy::move() {
	static int turn = 0;
	if (turn < getMovePattern().sleepTurns) {
		std::shared_ptr<MazeCell> cell = currentCell;
		for (uint8_t i = 0; i < getMovePattern().tilesNumber; ++i) {
			auto neighbours = cell->getNeighbours();
			std::uniform_int_distribution<> dis(0, neighbours.size() - 1);
			cell = (*std::next(std::begin(neighbours), dis(mt))).second.lock();
		}
		currentCell = cell;
	}
	return currentCell;
}
