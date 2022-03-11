//============================================================================
// Name        : CrowdedRoom.h
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
#include <artifact/Artifact.h>

class DungeonRoom: public Room {
private:
	std::vector<std::shared_ptr<Enemy>> enemies;
	std::shared_ptr<Artifact> artifact;

public:
	DungeonRoom();
	std::vector<std::shared_ptr<Enemy>> getEnemies();
	void addEnemy(std::shared_ptr<Enemy>);
	void removeEnemy(std::shared_ptr<Enemy>);

	std::shared_ptr<Artifact> getArtifact();
	void setArtifact(std::shared_ptr<Artifact>);
	std::shared_ptr<Artifact> pickupArtifact();
};

#endif /* MAZE_ROOM_DUNGEONROOM_H_ */
