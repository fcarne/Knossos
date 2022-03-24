//============================================================================
// Name        : Room.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================

#include <maze/room/Room.h>

#include <iostream>

#include <entity/Hero.h>
#include <utils/Constants.h>

Room::Room() :
		visible(false) {
}

void Room::setHero(std::shared_ptr<Hero> hero) {
	this->hero = hero;
	visible = visible || (hero != nullptr);
}

bool Room::isVisible() {
	return visible;
}

std::shared_ptr<Artifact> Room::getArtifact() {
	return artifact;
}

void Room::setArtifact(std::shared_ptr<Artifact> artifact) {
	this->artifact = artifact;
}

std::shared_ptr<Artifact> Room::pickupArtifact() {
	auto it = artifact;
	artifact = nullptr;
	return it;
}

void Room::draw() {
	auto hero = this->hero.lock();
	if (visible && hero != nullptr) {
		std::cout << hero->getSprite();
	} else {
		std::cout << constants::EMPTY_TILE;
	}
}

std::shared_ptr<Room> Room::clone() {
	return std::make_shared<Room>(*this);
}
