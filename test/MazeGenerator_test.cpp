//============================================================================
// Name        : Grid_test.cpp
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : MazeGenerator test
//============================================================================

#include <iostream>
#include <memory>

#include "../src/maze/MazeGenerator.h"
#include "../src/maze/algorithm/RecursiveDivision.h"
#include "../src/maze/algorithm/RandomizedPrim.h"
#include "../src/maze/algorithm/SideWinder.h"

#include <entity/Hero.h>

int main() {

	std::unique_ptr<MazeAlgorithm> algorithm;
	algorithm = std::make_unique<RecursiveDivision>();
	MazeGenerator generator(algorithm);
	std::unique_ptr<Maze> maze = generator.generate(5, 5);

	maze->draw(true);
	auto hero = std::shared_ptr<Hero>(new Hero("A", 1, 1, nullptr, "AA"));
	maze->getCell(2, 2)->getContent()->setHeroIn(hero);
	maze->draw(true);

	maze->getCell(1, 2)->getContent()->setHeroIn(hero);
	maze->draw(true);

	maze->getCell(2, 1)->getContent()->setHeroIn(hero);
	maze->draw(true);
	maze->getCell(2, 0)->getContent()->setHeroIn(hero);
	maze->draw(true);

	std::cout << *maze;
	return 0;
}

