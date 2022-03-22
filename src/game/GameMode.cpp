//============================================================================
// Name        : GameMode.cpp
// Author      : Federico Carne 1059865
// Date		   : 13 mar 2022
// Description : 
//============================================================================
#include <game/GameMode.h>

#include <iostream>
#include <cstdint>
#include <fstream>
#include <conio.h>

#include <utils/Constants.h>
#include <maze/MazeAlgorithm.h>
#include <maze/MazeGenerator.h>
#include <maze/algorithm/RandomizedPrim.h>
#include <maze/algorithm/RecursiveDivision.h>
#include <maze/algorithm/SideWinder.h>

GameMode::GameMode(Room roomInit) :
		room(roomInit) {
}

void GameMode::initGame() {
	std::cout << " --- PLAYER DATA ---\n\n";

	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	std::string tile;
	std::cout << "Enter your sprite (a two-characters string): ";
	std::getline(std::cin, tile);

	if (tile.length() < 2) {
		tile = constants::DEFAULT_HERO_SPRITE;
		std::cout << "Too short, defaulted to " << tile << "\n";
	} else if (tile.length() > 2) {
		tile = tile.substr(0, 2);
		std::cout << "Too long, shortened to " << tile << "\n";
	}

	std::cout << "\n\n --- MAZE DIMENSIONS ---\n\n";

	uint16_t height;
	do {
		std::cout << "Maze height (>=" << constants::MIN_MAZE_HEIGHT << "): ";
		std::cin >> height;
		if (height < constants::MIN_MAZE_HEIGHT) {
			std::cout << "Please, enter a valid size...\n";
		}
	} while (height < constants::MIN_MAZE_HEIGHT);

	uint16_t width;
	do {
		std::cout << "Maze width (>=" << constants::MIN_MAZE_WIDTH << "): ";
		std::cin >> width;
		if (width < constants::MIN_MAZE_WIDTH) {
			std::cout << "Please, enter a valid size...\n";
		}
	} while (width < constants::MIN_MAZE_WIDTH);

	std::cout << "\n\n --- GENERATION ALGORITHM ---\n\n";

	uint32_t seed;
	std::cout << "Random seed: ";
	std::cin >> seed;
	mt = std::mt19937(seed);

	int algorithmChoice;
	std::cout << "Select the generation algorithm\n";
	std::cout << "1) Randomized Prim\n";
	std::cout << "2) Recursive Division\n";
	std::cout << "3) SideWinder\n";
	do {
		std::cout << "Your choice: ";
		std::cin >> algorithmChoice;
		if (algorithmChoice < 1 || algorithmChoice > 3) {
			std::cout << "Please, enter a valid choice...\n";
		}
	} while (algorithmChoice < 1 || algorithmChoice > 3);

	std::unique_ptr<MazeAlgorithm> algorithm;
	switch (algorithmChoice) {
	case 1:
		algorithm = std::make_unique<RandomizedPrim>();
		break;
	case 2:
		algorithm = std::make_unique<RecursiveDivision>();
		break;
	default:
		algorithm = std::make_unique<SideWinder>();
		break;
	}

	MazeGenerator generator(algorithm);

	std::uniform_int_distribution<> disCol(0, width - 1);
	std::uniform_int_distribution<> disRow(0, height - 1);
	startingCoords = Coordinates(disCol(mt), disRow(mt));

	maze = generator.generate(height, width, false, startingCoords, room, seed);

	maze->setWinningMove(startingCoords, seed);

	auto cell = maze->getCell(startingCoords.row, startingCoords.col);
	hero = std::make_shared<Hero>(name, 256, 32, cell, tile);
	cell->getContent()->setHero(hero);
}

bool GameMode::checkArtifact(std::shared_ptr<Room> room) {
	auto artifact = room->getArtifact();

	if (artifact != nullptr && artifact->isAutomatic()) {
		std::cout << artifact->getDescription() << "\n";
		artifact->activate(hero);
		return true;
	} else
		return false;
}

bool GameMode::retry() {
	char retry;
	do {
		std::cout << "Do you want to retry? [y/n]\n";
		std::cin >> retry;
	} while (retry != 'y' && retry != 'n');

	return retry == 'y';
}

void GameMode::saveMaze() {
	char save;
	do {
		std::cout << "Do you want to save the maze? [y/n]\n";
		std::cin >> save;
	} while (save != 'y' && save != 'n');

	if (save == 'y') {
		std::string filename;
		std::cout << "Where do you want to save it? ";
		std::cin.ignore();
		std::getline(std::cin, filename);

		std::ofstream out(filename);
		out << *maze;
		out.close();

		std::cout << "Saved!\n";
	}
}

void GameMode::printHelp() {
	std::cout << "You are: " << hero->getSprite() << "\n";
	std::cout << "The exit is: " << constants::EXIT_TILE << "\n";

	std::cout << "You must hit enter to execute a command\n";
	std::cout << "To show this help, press " << HELP_KEY << "\n";
	std::cout << "To give up, press " << EXIT_KEY << "\n";
	std::cout << "To move press " << UP_KEY << LEFT_KEY << DOWN_KEY << RIGHT_KEY
			<< "\n";
}

std::pair<Direction, bool> GameMode::readUserInput() {
	char c;
	Direction d;
	bool wasDirection;
	do {
		wasDirection = true;
		std::cout << "Which direction do you wanna go? ";
		c = _getch();

		switch (c) {
		case UP_KEY:
			d = Direction::N;
			break;
		case DOWN_KEY:
			d = Direction::S;
			break;
		case LEFT_KEY:
			d = Direction::W;
			break;
		case RIGHT_KEY:
			d = Direction::E;
			break;
		case HELP_KEY:
			printHelp();
			wasDirection = false;
			break;
		case EXIT_KEY:
			return {Direction(), true};
			break;
		default:
			std::cout << "Please, enter a valid character\n";
			wasDirection = false;
		}

	} while (!wasDirection);

	return {d, false};

}

bool GameMode::setArtifact(std::shared_ptr<Artifact> artifact,
		std::vector<Coordinates> prohibited,
		std::uniform_int_distribution<> rowRange,
		std::uniform_int_distribution<> colRange) {

	Coordinates c(colRange(mt), rowRange(mt));

	while (std::find(prohibited.begin(), prohibited.end(), c)
			!= prohibited.end()) {
		c = Coordinates(colRange(mt), rowRange(mt));
	}

	maze->getCell(c.row, c.col)->getContent()->setArtifact(artifact);

	prohibited.push_back(c);
	return prohibited.size() < (maze->getWidth() * maze->getHeight());
}
