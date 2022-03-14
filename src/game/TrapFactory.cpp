//============================================================================
// Name        : TrapFactory.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#include <game/TrapFactory.h>

#include <string>
#include <functional>
#include <chrono>
#include <libs/mingw-std-threads/mingw.thread.h>

#include <entity/Hero.h>

TrapFactory::TrapFactory(uint32_t seed) :
		mt(seed), dis(0.9, 1.1) {
}

std::shared_ptr<Trap> TrapFactory::make_trap(TrapType type) {

	std::shared_ptr<Trap> trap;
	switch (type) {
	case TrapType::SPIKES: {
		auto effect = [trap](std::shared_ptr<Hero> hero) {
			hero->defend(trap->getDamage());
		};

		trap = std::make_shared<Trap>("Spikes",
				"A set of rusted spikes hits and damages you",
				20 * (int) dis(mt), effect);
		break;
	}
	case TrapType::ICE_SLOPE: {
		auto effect = [=](std::shared_ptr<Hero> hero) {
			auto directions = hero->getCell()->getNeighboursDirection();
			std::uniform_int_distribution<> dis(0, directions.size());
			Direction d = directions.at(dis(mt));
			hero->move(d);
		};

		trap =
				std::make_shared<Trap>("Ice slope",
						"An ice slope makes you slip through the room and to the next one",
						0, effect);
		break;
	}
	case TrapType::COLLAPSED_ROOF: {
		auto effect = [trap](std::shared_ptr<Hero> hero) {
			hero->defend(trap->getDamage());
			hero->unequipWeapon();
		};

		trap = std::make_shared<Trap>("Collapsed roof",
				"The roof suddenly collapse, you avoid it but lose your weapon",
				5, effect);
		break;
	}
	case TrapType::FIRE_ARROWS: {
		auto effect = [trap](std::shared_ptr<Hero> hero) {
			hero->defend(trap->getDamage());
			auto armor = hero->getArmor();
			armor->setDefense(armor->getDefense() * 3 / 4 + 1);
			;
		};

		trap =
				std::make_shared<Trap>("Fire arrows",
						"A set of fire arrows shot at you burns your armor and decreases its defense",
						10, effect);
		break;
	}
	case TrapType::POISONED_BARBS: {
		auto effect = [=](std::shared_ptr<Hero> hero) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		};

		trap =
				std::make_shared<Trap>("Poisoned barbs",
						"Poisoned barbs scattered all over the floor, you touch one and momentarily can't move",
						0, effect);
		break;
	}
	default:
		break;
	}

	return trap;
}
