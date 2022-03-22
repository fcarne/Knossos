//============================================================================
// Name        : Weapon.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef ARTIFACT_WEAPON_H_
#define ARTIFACT_WEAPON_H_

#include <artifact/Artifact.h>

#include <memory>

class Weapon: public Artifact, public std::enable_shared_from_this<Weapon> {
private:
	uint16_t damage;
public:
	Weapon(std::string name, std::string description, uint16_t damage);
	uint16_t getDamage();
	void setDamage(uint16_t);
	std::string toString() override;
};

#endif /* ARTIFACT_WEAPON_H_ */
