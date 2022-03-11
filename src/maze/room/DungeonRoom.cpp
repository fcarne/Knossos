//============================================================================
// Name        : CrowdedRoom.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include <maze/room/DungeonRoom.h>

DungeonRoom::DungeonRoom() {
	artifact = nullptr;
}

std::vector<std::shared_ptr<Enemy>> DungeonRoom::getEnemies() {
	return enemies;
}

void DungeonRoom::addEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.push_back(enemy);
}

void DungeonRoom::removeEnemy(std::shared_ptr<Enemy> enemy) {
	enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy),
			enemies.end());
}

std::shared_ptr<Artifact> DungeonRoom::getArtifact() {
	return artifact;
}

void DungeonRoom::setArtifact(std::shared_ptr<Artifact> artifact) {
	this->artifact = artifact;
}

std::shared_ptr<Artifact> DungeonRoom::pickupArtifact() {
	auto it = artifact;
	artifact = nullptr;
	return it;
}
