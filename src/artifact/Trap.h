//============================================================================
// Name        : Trap.h
// Author      : Federico Carne 1059865
// Date		   : 25 feb 2022
// Description : 
//============================================================================
#ifndef ARTIFACT_TRAP_H_
#define ARTIFACT_TRAP_H_

#include <cstdint>
#include <string>

#include <artifact/Artifact.h>

class Trap: public Artifact {
private:
	uint8_t damage;
public:
	Trap(std::string name, std::string description, uint8_t damage,
			std::function<void(std::shared_ptr<Hero>)> effect);
	uint8_t getDamage();
};

#endif /* ARTIFACT_TRAP_H_ */
