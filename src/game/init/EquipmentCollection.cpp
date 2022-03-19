//============================================================================
// Name        : EquipmentCollection.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#include <game/init/EquipmentCollection.h>

#include <experimental/algorithm>
#include <functional>

#include <utils/Utils.h>

EquipmentCollection::EquipmentCollection(uint32_t seed) :
		mt(seed) {
}

std::vector<std::shared_ptr<Armor>> EquipmentCollection::getArmors() {
	return armorList;
}
std::vector<std::shared_ptr<Weapon>> EquipmentCollection::getWeapons() {
	return weaponList;
}

std::vector<std::shared_ptr<Armor>> EquipmentCollection::pickArmors(uint8_t n) {
	std::vector<std::shared_ptr<Armor>> selected;

	std::experimental::sample(armorList.begin(), armorList.end(),
			std::back_inserter(selected), n, mt);

	return selected;
}

std::vector<std::shared_ptr<Weapon>> EquipmentCollection::pickWeapons(
		uint8_t n) {
	std::vector<std::shared_ptr<Weapon>> selected;

	std::experimental::sample(weaponList.begin(), weaponList.end(),
			std::back_inserter(selected), n, mt);

	return selected;
}

void EquipmentCollection::loadArmors(std::string filename) {
	std::function<std::shared_ptr<Armor>(nlohmann::json)> parser = [](
			nlohmann::json armor) {
		return std::make_shared<Armor>(armor["name"], armor["description"],
				armor["defense"]);
	};

	utils::parseJsonIntoList(filename, armorList, parser);

}

void EquipmentCollection::loadWeapons(std::string filename) {
	std::function<std::shared_ptr<Weapon>(nlohmann::json)> parser = [](
			nlohmann::json weapon) {
		return std::make_shared<Weapon>(weapon["name"], weapon["description"],
				weapon["damage"]);
	};

	utils::parseJsonIntoList(filename, weaponList, parser);
}
