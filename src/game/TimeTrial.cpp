//============================================================================
// Name        : TimeTrial.cpp
// Author      : Federico Carne 1059865
// Date		   : 16 mar 2022
// Description : 
//============================================================================
#include <game/TimeTrial.h>

#include <chrono>
#include <tuple>
#include <random>
#include <cstdint>

#include <maze/room/Room.h>
#include <game/init/TrapFactory.h>

TimeTrial::TimeTrial() :
		GameMode(Room()) {
}

void TimeTrial::initGame() {
	GameMode::initGame();

	std::cout << "\n\n --- TRAPS ---\n\n";

	uint16_t nTraps;
	std::cout << "Number of traps: ";
	std::cin >> nTraps;

	std::uniform_int_distribution<> disCol(0, maze->getLastColumnIndex());
	std::uniform_int_distribution<> disRow(0, maze->getLastRowIndex());
	TrapFactory factory;

	std::vector<Coordinates> prohibited;
	prohibited.push_back(startingCoords);

	for (uint16_t i = 0u; i < nTraps; i++) {
		auto trap = factory.make_trap(TrapType::POISONED_BARBS);
		Coordinates c(disCol(mt), disRow(mt));

		while (std::find(prohibited.begin(), prohibited.end(), c)
				!= prohibited.end()) {
			c = Coordinates(disCol(mt), disRow(mt));
		}

		maze->getCell(c.row, c.col)->getContent()->setArtifact(trap);

		prohibited.push_back(c);
		if (prohibited.size() == maze->getWidth() * maze->getHeight())
			break;
	}

	std::cout << "Setup complete!\n";

}
void TimeTrial::play() {
	std::cout
			<< "When you're ready, press the Enter key... Remember, you have to be fast!\n";
	std::cin.ignore();
	std::cin.get();
	utils::clear_screen();

	bool finish = false;
	bool moved = false;

	auto start = std::chrono::high_resolution_clock::now();
	while (!finish) {
		maze->draw(true);
		checkArtifact(hero->getCell()->getContent());

		//moved = false;
		do {
			auto [d, quit] = readUserInput();

			if (quit)
				return;

			finish = maze->checkWinningMove(hero->getCell(), d);

			if (!finish) {
				moved = hero->move(d);
				if (!moved) {
					std::cout << "You can't go in that direction\n";
				}
			}
		} while (!moved);

		utils::clear_screen();
	}

	// stop timer, give result, ask for save and retry
	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << "Congratulations " << hero->getName()
			<< ", you found the exit!\n";

	auto duration = utils::break_down_durations<std::chrono::minutes,
			std::chrono::seconds>(stop - start);

	std::cout << "Completed in: " << std::get<0>(duration).count()
			<< " minutes and " << std::get<1>(duration).count() << " seconds\n";

	std::cin.ignore();
	saveMaze();

}

void TimeTrial::printDescription() {
	std::cout << "Time trial:\n";
	std::cout
			<< "Run through the maze and find the exit in the least time possible.\n";
	std::cout
			<< "Beware, there will be poisoned traps that will paralyze you!\n\n";

	std::cout << "Help:\n";
	printHelp();

	std::cout << "Press any key to continue...\n";
	std::cin.ignore();
}
