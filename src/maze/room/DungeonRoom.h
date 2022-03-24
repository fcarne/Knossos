//============================================================================
// Name        : DungeonRoom.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_ROOM_DUNGEONROOM_H_
#define MAZE_ROOM_DUNGEONROOM_H_

#include <vector>
#include <memory>

#include <maze/room/Room.h>
#include <entity/Enemy.h>

class DungeonRoom: public Room {
private:
	std::vector<std::weak_ptr<Enemy>> enemies;

public:
	DungeonRoom();
	void addEnemy(std::shared_ptr<Enemy>);
	void removeEnemy(std::shared_ptr<Enemy>);
	std::shared_ptr<Enemy> getFirstEnemy();
	bool isEmpty();
	void draw() override;
	std::shared_ptr<Room> clone() override;
};

#endif /* MAZE_ROOM_DUNGEONROOM_H_ */
