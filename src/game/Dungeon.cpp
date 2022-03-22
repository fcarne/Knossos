//============================================================================
// Name        : Dungeon.cpp
// Author      : Federico Carne 1059865
// Date		   : 21 mar 2022
// Description : 
//============================================================================
#include <game/Dungeon.h>

#include <chrono>
#include <tuple>
#include <random>
#include <cstdint>
#include <conio.h>

#include <maze/room/DungeonRoom.h>
#include <game/init/TrapFactory.h>
#include <game/init/EquipmentCollection.h>
#include <game/init/BreedCollection.h>

Dungeon::Dungeon() :
		GameMode(DungeonRoom()) {
}

void Dungeon::initGame() {
	GameMode::initGame();

	std::uniform_int_distribution<> colRange(0, maze->getLastColumnIndex());
	std::uniform_int_distribution<> rowRange(0, maze->getLastRowIndex());
	std::vector<Coordinates> prohibited;
	prohibited.push_back(startingCoords);

	std::cout << "\n\n --- EQUIPMENT ---\n\n";
	EquipmentCollection equipment(mt());

	uint16_t nWeapons;
	std::string weaponsFilename;
	std::cout << "Weapons file path: ";
	std::cin.ignore();
	std::getline(std::cin, weaponsFilename);
	std::cout << "Number of weapons: ";
	std::cin >> nWeapons;

	equipment.loadWeapons(weaponsFilename);
	auto weapons = equipment.pickWeapons(nWeapons);

	for (std::shared_ptr<Weapon> w : weapons) {
		bool stillSpace = setArtifact(w, prohibited, rowRange, colRange);
		if (!stillSpace)
			break;
	}

	uint16_t nArmors;
	std::string armorsFilename;
	std::cout << "Armors file path: ";
	std::cin.ignore();
	std::getline(std::cin, armorsFilename);
	std::cout << "Number of armors: ";
	std::cin >> nArmors;

	equipment.loadArmors(armorsFilename);
	auto armors = equipment.pickArmors(nArmors);

	for (std::shared_ptr<Armor> a : armors) {
		bool stillSpace = setArtifact(a, prohibited, rowRange, colRange);
		if (!stillSpace)
			break;
	}

	std::cout << "\n\n --- TRAPS ---\n\n";

	uint16_t nTraps;
	std::cout << "Number of traps: ";
	std::cin >> nTraps;

	std::uniform_int_distribution<> trapType(0, 4);
	TrapFactory factory;

	for (uint16_t i = 0u; i < nTraps; i++) {
		auto trap = factory.make_trap(static_cast<TrapType>(trapType(mt)));
		bool stillSpace = setArtifact(trap, prohibited, rowRange, colRange);
		if (!stillSpace)
			break;
	}

	std::cout << "\n\n --- ENEMIES ---\n\n";

	std::string breedsFilename;
	std::cout << "Breeds file path: ";
	std::cin.ignore();
	std::getline(std::cin, breedsFilename);

	BreedCollection breedCollection(mt());
	breedCollection.loadBreeds(breedsFilename);
	auto breeds = breedCollection.getBreeds();

	for (auto b : breeds) {
		std::shared_ptr<Breed> breed = b.second;
		while (breed->getBreedPopulation() > 0) {
			Coordinates c(colRange(mt), rowRange(mt));
			while (c == startingCoords)
				c = Coordinates(colRange(mt), rowRange(mt));

			auto room = std::dynamic_pointer_cast<DungeonRoom>(
					maze->getCell(c.row, c.col)->getContent());
			auto enemy = breed->newEnemy(maze->getCell(c.row, c.col));

			room->addEnemy(enemy);
			enemies.push_back(enemy);
		}
	}

	auto startingWeapon = std::make_shared<Weapon>("Wooden sword",
			"A normal wooden sword", 64);
	auto startingArmor = std::make_shared<Armor>("Leather chestplate",
			"A normal leather chestplate", 64);

	hero->equipWeapon(startingWeapon);
	hero->equipArmor(startingArmor);

	std::cout << "---------------\n";
	std::cout << "Setup complete!\n\n";

}

void Dungeon::play() {
	std::cout << "Help:\n";
		printHelp();
	std::cout
			<< "When you're ready, press the Enter key... Remember, kill'em all!\n";
	std::cin.ignore();
	std::cin.get();
	utils::clear_screen();

	bool finish = false;
	bool gameOver = false;
	bool moved = false;

	auto start = std::chrono::high_resolution_clock::now();
	while (!finish && !gameOver) {
		auto room = std::dynamic_pointer_cast<DungeonRoom>(
				hero->getCell()->getContent());
		bool automatic = checkArtifact(room);
		maze->draw(true);

		auto roomEnemies = room->getEnemies();
		bool escaped;

		while (!roomEnemies.empty() && !gameOver) {
			std::shared_ptr<Enemy> enemy = roomEnemies[0].lock();
			auto [killed, _escaped, quit] = fight(enemy);

			if (quit)
				return;

			if (killed)
				room->removeEnemy(enemy);
			else if (hero->getHp() < 0)
				gameOver = true;

			escaped = _escaped;
			if (_escaped)
				break;
		}

		if (gameOver)
			break;

		if (!automatic && !escaped) {
			std::cout << "You found an artifact in this room.\n";
			std::cout << room->getArtifact()->toString() << "\n";

			char pickup;
			do {
				std::cout << "Do you want to pickup the artifact? [y/n]\n";
				std::cin >> pickup;
			} while (pickup != 'y' && pickup != 'n');

			if (pickup == 'y') {
				room->pickupArtifact()->activate(hero);
			}
		}

		if (enemies.empty()) {
			std::cout << "You defeated all the enemies, now go to the exit!\n";
		}

		do {
			auto [d, quit] = readUserInput();

			if (quit)
				return;

			bool winningMove = maze->checkWinningMove(hero->getCell(), d);

			finish = winningMove && enemies.empty();

			if (winningMove && !enemies.empty()) {
				std::cout
						<< "To unlock the exit, you have to defeat the remaining "
						<< enemies.size() << " enemies.\n";
			}

			if (!finish) {
				moved = hero->move(d);
				if (!moved) {
					std::cout << "You can't go in that direction\n";
				}
			}
		} while (!moved);

		std::for_each(enemies.begin(), enemies.end(),
				[=](std::shared_ptr<Enemy> e) {
					e->move();
				});

		utils::clear_screen();
	}

// stop timer, give result, ask for save and retry
	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << "Congratulations " << hero->getName()
			<< ", you survived in the dungeon!\n";

	auto duration = utils::break_down_durations<std::chrono::minutes,
			std::chrono::seconds>(stop - start);

	std::cout << "Completed in: " << std::get<0>(duration).count()
			<< " minutes and " << std::get<1>(duration).count() << " seconds\n";

	std::cin.ignore();
	saveMaze();

}

void Dungeon::printHelp() {
	GameMode::printHelp();
	std::cout << "During a fight press " << ATTACK_KEY << " to attack and "
			<< RUN_AWAY_KEY << " to try to escape\n";
}

void Dungeon::printDescription() {
	std::cout << "Dungeon:\n";
	std::cout
			<< "Explore the dungeon, collect weapons and and fights hordes of enemies.\n";
	std::cout
			<< "Pay attention, there will also be some traps that can damage you or change your plan!\n\n";

	std::cout << "Press any key to continue...\n";
	std::cin.ignore();
}

std::tuple<bool, bool, bool> Dungeon::fight(std::shared_ptr<Enemy> enemy) {
	char c;
	bool wasFightInput;

	std::cout << "An enemy appeared, prepare to fight!\n";
	std::cout << "Enemy details:\n";
	std::cout << "Breed: " << enemy->getBreedName() << "\n";
	std::cout << "HP: " << enemy->getHp() << "\n";
	std::cout << "Damage: " << enemy->getBreedName() << "\n";

	std::uniform_int_distribution<> dungeonDice(1, 20);

	do {

		do {
			wasFightInput = true;
			std::cout << "What do you wanna do, attack or try to escape?: ";
			c = _getch();

			int rolled;
			switch (c) {
			case ATTACK_KEY: {
				rolled = dungeonDice(mt);
				uint16_t damageDone = 0;
				if (rolled <= 3)
					std::cout << "Snap, you missed!\n";
				else if (rolled >= 18) {
					std::cout << "The " << enemy->getBreedName()
							<< " is open, hit it twice!\n";
					damageDone = hero->attack(enemy);
					damageDone += hero->attack(enemy);
				} else {
					damageDone = hero->attack(enemy);
				}

				std::cout << "Damage done: " << damageDone << ". Enemy's HP: "
						<< enemy->getHp();
				break;
			}
			case RUN_AWAY_KEY:
				rolled = dungeonDice(mt);
				if (rolled >= 5) {
					std::cout << "You ran away!\n";
					return {false, true, false};
				}
				break;

			case GameMode::HELP_KEY:
				printHelp();
				wasFightInput = false;
				break;
			case GameMode::EXIT_KEY:
				return {false, false, true};
				break;
			default:
				std::cout << "Please, enter a valid character\n";
				wasFightInput = false;
			}
		} while (wasFightInput);

		if (enemy->getHp() > 0) {
			std::cout << enemy->getAttackString() << "\n";
			uint16_t damageReceived = enemy->attack(hero);
			std::cout << "Damage received: " << damageReceived
					<< ". Remaining HP: " << hero->getHp();
		}

	} while (enemy->getHp() > 0 && hero->getHp() > 0);

	return {hero->getHp() > 0, false, false};

}
