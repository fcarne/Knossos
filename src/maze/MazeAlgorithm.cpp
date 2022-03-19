//============================================================================
// Name        : MazeAlgorithm.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================

#include <maze/MazeAlgorithm.h>

#include <chrono>
#include <thread>
#include <utils/Utils.h>

void MazeAlgorithm::printWhileConstructing(Maze &maze, bool showConstruction) {
	if (showConstruction) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		utils::clear_screen();
		maze.draw();
	}
}
