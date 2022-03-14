//============================================================================
// Name        : CrowdedRoom.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <maze/room/DungeonRoom.h>

#include <iostream>

#include <entity/Hero.h>
#include <utils/Constants.h>

std::vector<std::weak_ptr<Enemy>> DungeonRoom::getEnemies() {
	return enemies;
}

void DungeonRoom::addEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.push_back(enemy);
}

void DungeonRoom::removeEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.erase(
			std::remove_if(enemies.begin(), enemies.end(),
					[enemy](std::weak_ptr<Enemy> e) {
						return e.lock() == enemy;
					}),
			enemies.end());
}

void DungeonRoom::draw() {
	auto hero = this->hero.lock();
	if (visible && hero != nullptr) {
		std::cout << hero->getTile();
	} else if (visible && !enemies.empty()) {
		std::cout << enemies.at(0).lock()->getTile();
	} else {
		std::cout << constants::EMPTY_TILE;
	}
}
