//============================================================================
// Name        : EquipmentCollection.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef GAME_INIT_EQUIPMENTCOLLECTION_H_
#define GAME_INIT_EQUIPMENTCOLLECTION_H_

#include <vector>
#include <memory>
#include <random>
#include <string>
#include <cstdint>

#include <artifact/equipment/Armor.h>
#include <artifact/equipment/Weapon.h>

class EquipmentCollection {
private:
	std::vector<std::shared_ptr<Armor>> armorList;
	std::vector<std::shared_ptr<Weapon>> weaponList;
	std::mt19937 mt;
public:
	EquipmentCollection(uint32_t seed = 0);
	std::vector<std::shared_ptr<Armor>> getArmors();
	std::vector<std::shared_ptr<Weapon>> getWeapons();

	std::vector<std::shared_ptr<Armor>> pickArmors(uint16_t);
	std::vector<std::shared_ptr<Weapon>> pickWeapons(uint16_t);

	void loadArmors(std::string);
	void loadWeapons(std::string);
};

#endif /* GAME_INIT_EQUIPMENTCOLLECTION_H_ */
