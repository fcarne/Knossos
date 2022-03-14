//============================================================================
// Name        : BreedCollection.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#include <game/BreedCollection.h>

#include <functional>
#include <utils/Utils.h>

BreedCollection::BreedCollection(uint32_t seed) :
		mt(seed) {
}

std::unordered_map<std::string, std::shared_ptr<Breed>> BreedCollection::getBreeds() {
	return breedMap;
}

std::shared_ptr<Breed> BreedCollection::getBreed(std::string breedName) {
	return breedMap.at(breedName);
}

std::vector<std::string> BreedCollection::getBreedNames() {
	return utils::keyList(breedMap);
}

void BreedCollection::loadBreeds(std::string filename) {
	std::function<std::pair<std::string, std::shared_ptr<Breed>>(nlohmann::json)> parser =
			[](nlohmann::json breed) -> std::pair<std::string, std::shared_ptr<Breed>> {
				MovePattern pattern;
				pattern.tilesNumber = breed["pattern"]["tilesNumber"];
				pattern.tilesNumber = breed["pattern"]["tilesNumber"];

				return std::make_pair(breed["name"],
						std::make_shared<Breed>(breed["maxHp"], breed["damage"],
								breed["attackString"], breed["breedName"],
								pattern, breed["tile"]));
			};

	utils::parseJsonIntoMap(filename, breedMap, parser);
}
