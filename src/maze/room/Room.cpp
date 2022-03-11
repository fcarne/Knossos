//============================================================================
// Name        : Room.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================

#include <maze/room/Room.h>

Room::Room(): heroIn(false) {}

bool Room::isHeroIn() {
	return heroIn;
}

void Room::setHeroIn(bool in) {
	heroIn = in;
}
