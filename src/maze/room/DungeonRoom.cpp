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

DungeonRoom::DungeonRoom() {
}

void DungeonRoom::addEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.push_back(enemy);
}

void DungeonRoom::removeEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.remove_if([enemy](std::weak_ptr<Enemy> e) {
		return e.lock() == enemy;
	});
}

std::shared_ptr<Enemy> DungeonRoom::getFirstEnemy() {
	return enemies.front().lock();
}

bool DungeonRoom::isEmpty() {
	return enemies.empty();
}

std::string DungeonRoom::draw() {
	auto hero = this->hero.lock();
	if (visible && hero != nullptr)
		return hero->getSprite();
	else if (visible && !enemies.empty())
		return (enemies.front().lock()->getSprite());
	else
		return constants::EMPTY_TILE;
}

std::shared_ptr<Room> DungeonRoom::clone() {
	return std::make_shared<DungeonRoom>(*this);
}
