//============================================================================
// Name        : Daedalus.cpp
// Author      : Federico Carne 1059865
// Date		   : 24 mar 2022
// Description : 
//============================================================================
#include <game/Daedalus.h>

Daedalus::Daedalus() :
		GameMode(std::make_shared<Room>(), true) {
}

void Daedalus::initGame() {
	generateMaze();
}

bool Daedalus::play() {
	saveMaze();
	return retry();
}

void Daedalus::printDescription() {
	std::cout << "Daedalus mode:\n";
	std::cout << "Generate incredible mazes and watch them come alive!\n";
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
}
