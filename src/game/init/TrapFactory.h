//============================================================================
// Name        : TrapFactory.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef ARTIFACT_TRAPFACTORY_H_
#define ARTIFACT_TRAPFACTORY_H_

#include <cstdint>
#include <memory>
#include <random>

#include <artifact/Trap.h>

enum class TrapType : uint8_t {
	SPIKES /* damage */,
	ICE_SLOPE /* moves randomly */,
	COLLAPSED_ROOF /*removes weapon*/,
	FIRE_ARROWS /* halves defense */,
	POISONED_BARBS /* paralyzes - stops time*/
};

class TrapFactory {
private:
	std::mt19937 mt;
	std::uniform_real_distribution<> dis;
public:
	TrapFactory(uint32_t seed = 0);
	std::shared_ptr<Trap> make_trap(TrapType type);
};

#endif /* ARTIFACT_TRAPFACTORY_H_ */
