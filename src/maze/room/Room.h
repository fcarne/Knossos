//============================================================================
// Name        : Room.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : Room and subclasses definition
//============================================================================
#ifndef MAZE_ROOM_H_
#define MAZE_ROOM_H_

class Room {
private:
	bool heroIn;
public:
	Room();
	bool isHeroIn();
	void setHeroIn(bool);
};

#endif /* MAZE_ROOM_H_ */
