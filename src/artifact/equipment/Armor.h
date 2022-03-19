//============================================================================
// Name        : Armor.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef ARTIFACT_ARMOR_H_
#define ARTIFACT_ARMOR_H_

#include <memory>

#include <artifact/Artifact.h>

class Armor: public Artifact, public std::enable_shared_from_this<Armor> {
private:
	uint16_t defense;
public:
	Armor(std::string name, std::string description, uint16_t defense);
	uint16_t getDefense();
	void setDefense(uint16_t);
};

#endif /* ARTIFACT_ARMOR_H_ */
