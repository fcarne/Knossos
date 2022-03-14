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


int main() {

	std::unique_ptr<MazeAlgorithm> algorithm;
	algorithm = std::make_unique<RecursiveDivision>();
	MazeGenerator generator(algorithm);
	std::unique_ptr<Maze> maze = generator.generate(5, 5);

	maze->draw();

	std::cout << *maze;
	return 0;
}

