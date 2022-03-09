//============================================================================
// Name        : EnemyFactory.h
// Author      : Federico Carne 1059865
// Date		   : 3 mar 2022
// Description : 
//============================================================================
#ifndef ENTITY_ENEMYFACTORY_H_
#define ENTITY_ENEMYFACTORY_H_

#include <string>
#include <functional>
#include <memory>
#include <unordered_map>

#include <maze/Maze.h>
#include <entity/Enemy.h>

class EnemyFactory {
private:
	std::unordered_map<std::string, std::function<void(MazeCell&)>> types;
public:
	EnemyFactory(bool addDefault = true);
	bool registerType(std::string type, std::function<void(MazeCell&)> _move = nullptr);
	bool unregisterType(std::string type);
	std::shared_ptr<Enemy> create(std::string type);
};

#endif /* ENTITY_ENEMYFACTORY_H_ */
