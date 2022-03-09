//============================================================================
// Name        : EnemyFactory.cpp
// Author      : Federico Carne 1059865
// Date		   : 3 mar 2022
// Description : 
//============================================================================
#include <entity/factory/EnemyFactory.h>

EnemyFactoryEnemyFactory(bool addDefault) {
	if(addDefault) {

	}
}

bool EnemyFactory::registerType(std::string type,
		std::function<void(MazeCell&)> _move) {
	return types.insert(std::make_pair(type, _move)).second;
}

bool EnemyFactory::unregisterType(std::string type) {
	return types.erase(type);
}
