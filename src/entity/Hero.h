//============================================================================
// Name        : Hero.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef ENTITY_HERO_H_
#define ENTITY_HERO_H_

#include <entity/WanderingEntity.h>

class Hero: public WanderingEntity {
public:
	Hero();
	virtual ~Hero();
};

#endif /* ENTITY_HERO_H_ */
