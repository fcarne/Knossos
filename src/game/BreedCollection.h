//============================================================================
// Name        : BreedCollection.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef GAME_BREEDCOLLECTION_H_
#define GAME_BREEDCOLLECTION_H_

#include <vector>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include <entity/Breed.h>

class BreedCollection {
private:
	std::unordered_map<std::string, std::shared_ptr<Breed>> breedMap;
	std::mt19937 mt;
public:
	BreedCollection(uint32_t seed = 0);
	std::unordered_map<std::string, std::shared_ptr<Breed>> getBreeds();
	std::shared_ptr<Breed> getBreed(std::string);
	std::vector<std::string> getBreedNames();
	void loadBreeds(std::string);
};

#endif /* GAME_BREEDCOLLECTION_H_ */
