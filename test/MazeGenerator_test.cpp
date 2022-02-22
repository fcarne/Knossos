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


int main() {

	std::unique_ptr<MazeAlgorithm> algorithm;
	algorithm = std::make_unique<RecursiveDivision>();
	MazeGenerator generator(algorithm);
	std::unique_ptr<Maze> maze = generator.generate(5, 5, Point(0,0), Room(), 0);

	maze->print();
	return 0;
}

