//============================================================================
// Name        : WanderingEntity.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_WANDERINGENTITY_H_
#define ENTITY_WANDERINGENTITY_H_

#include <entity/Entity.h>

class WanderingEntity: public Entity {
private:
	std::function<void(MazeCell&)> _move;
public:
	WanderingEntity(int16_t hp, int16_t damage, std::shared_ptr<MazeCell> cell,
			std::string name, std::string type,
			std::function<void(MazeCell&)> _move);

	void move();
};

#endif /* ENTITY_WANDERINGENTITY_H_ */
