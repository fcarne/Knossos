//============================================================================
// Name        : Room.h
// Author      : Federico Carne 1059865
// Date		   : 26 gen 2022
// Description : Room and subclasses definition
//============================================================================
#ifndef MAZE_ROOM_H_
#define MAZE_ROOM_H_

#include <vector>
#include <memory>

#include <artifact/Artifact.h>

class Hero;

class Room {
protected:
	std::weak_ptr<Hero> hero;
	bool visible;
	std::shared_ptr<Artifact> artifact;
public:
	Room();
	virtual ~Room() = default;

	void setHero(std::shared_ptr<Hero>);
	bool isVisible();

	std::shared_ptr<Artifact> getArtifact();
	void setArtifact(std::shared_ptr<Artifact>);
	std::shared_ptr<Artifact> pickupArtifact();

	virtual void draw();
};

#endif /* MAZE_ROOM_H_ */
