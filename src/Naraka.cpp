//============================================================================
// Name        : Naraka.cpp
// Author      : Federico Carne 1059865
// Date        : 30/12/2021
// Description : Main function
//============================================================================

#include <iostream>
#include <string>
#include <memory>

#include <game/GameMode.h>
#include <game/TimeTrial.h>

int main() {
	std::string title =
			R"( _   _                 _         
| \ | |               | |        
|  \| | __ _ _ __ __ _| | ____ _ 
| . ` |/ _` | '__/ _` | |/ / _` |
| |\  | (_| | | | (_| |   < (_| |
\_| \_/\__,_|_|  \__,_|_|\_\__,_|
                                                               
)";
	std::cout << title;
	std::cout << "Welcome to Naraka, the maze game!\n";

	int choice;
	std::cout << "Which mode do you wanna play?\n";
	std::cout << "1) Time trial mode\n";
	std::cout << "2) Dungeon mode\n";
	std::cout << "0) Exit\n";
	do {
		std::cout << "Your choice: ";
		std::cin >> choice;
		if (choice < 0 || choice > 2) {
			std::cout << "Please, enter a valid choice...\n";
		}
	} while (choice < 0 || choice > 2);

	std::cin.ignore();

	std::unique_ptr<GameMode> mode;

	switch (choice) {
	case 1:
		mode = std::make_unique<TimeTrial>();
		break;
	case 2:
		//mode = std::make_unique<TimeTrial>();
		break;
	default:
		std::cout << "See you later then\n";
		return 0;
	}

	std::cout << "\n";
	mode->printDescription();
	std::cout << "\n";
	mode->initGame();
	mode->play();

	std::cout << "Thanks for playing\n";
	return 0;
}
