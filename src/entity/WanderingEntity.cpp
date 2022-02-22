//============================================================================
// Name        : WanderingEntity.cpp
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#include "WanderingEntity.h"

WanderingEntity::WanderingEntity(int16_t hp, int16_t damage,
		std::shared_ptr<MazeCell> cell, std::string name, std::string type,
		std::function<void(MazeCell&)> _move) :
		Entity(hp, damage, cell, name, type), _move(_move) {
}

void WanderingEntity::move() {
	_move(*currentCell);
}
