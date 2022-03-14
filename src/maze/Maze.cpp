//============================================================================
// Name        : Maze.cpp
// Author      : Federico Carne 1059865
// Date		   : 19 feb 2022
// Description : 
//============================================================================

#include <maze/Maze.h>

#include <iostream>
#include <random>

#include <utils/Constants.h>

void Maze::draw(bool drawRooms) {

	std::shared_ptr<MazeCell> cell;
	std::shared_ptr<Room> room;

	// NORTH BOUND - ALWAYS
	std::cout << constants::WALL_TILE;
	for (uint16_t j = 0; j < getWidth(); ++j) {
		bool exit = winningDirection == Direction::N && j == winningRoom.col;
		std::cout
				<< (exit && drawRooms ?
						constants::EXIT_TILE : constants::WALL_TILE)
				<< constants::WALL_TILE;
	}
	std::cout << "\n";

	for (uint16_t i = 0; i < getHeight(); ++i) {
		// WEST BOUND 1 - ALWAYS
		bool exit = winningDirection == Direction::W && i == winningRoom.row;
		std::cout
				<< (exit && drawRooms ?
						constants::EXIT_TILE : constants::WALL_TILE);

		// FIRST ROW
		for (uint16_t j = 0; j < getWidth(); ++j) {
			cell = getCell(i, j);
			room = cell->getContent();
			bool visible = room->isVisible();

			// DRAW ROOM
			if (drawRooms && visible)
				room->draw();
			else
				std::cout << constants::EMPTY_TILE;

			// DRAW EAST WALL - LAST CELL OR HASN'T NEIGHBOUR, IF drawRooms CHECK IF ONE OF THE TWO ROOMS IS VISIBLE
			bool lastIndex = j == getLastColumnIndex();
			bool drawEastWall =
					lastIndex || (!(cell->hasNeighbourInDirection(Direction::E)) &&
							(!drawRooms || visible
											|| getCell(i, j + 1)->getContent()->isVisible()));


			bool exit = lastIndex && winningDirection == Direction::E
					&& i == winningRoom.row;

			if (exit && drawRooms)
				std::cout << constants::EXIT_TILE;
			else
				std::cout
						<< (drawEastWall ?
								constants::WALL_TILE : constants::EMPTY_TILE);
		}

		// WEST BOUND 2 - ALWAYS
		std::cout << "\n" << constants::WALL_TILE;

		// SECOND ROW
		for (uint16_t j = 0; j < getWidth(); ++j) {

			cell = getCell(i, j);
			room = cell->getContent();
			bool visible = room->isVisible();

			// DRAW SOUTH WALL - LAST CELL OR HASN'T NEIGHBOUR AND ONE OF THE TWO ROOMS IS VISIBLE
			bool lastIndex = i == getLastRowIndex();
			bool drawSoutWall =
					lastIndex || (!cell->hasNeighbourInDirection(Direction::S) &&
							(!drawRooms || visible
											|| getCell(i + 1, j)->getContent()->isVisible()));

			bool exit = lastIndex && winningDirection == Direction::S
					&& j == winningRoom.col;
			if (exit || drawRooms)
				std::cout << constants::EXIT_TILE;
			else
				std::cout
						<< (drawSoutWall ?
								constants::WALL_TILE : constants::EMPTY_TILE);

			// DRAW SOUTH-EAST WALL
			std::cout
					<< (!drawRooms || visible
							|| getCell(i, j + 1)->getContent()->isVisible()
							|| getCell(i + 1, j)->getContent()->isVisible() ?
							constants::WALL_TILE : constants::EMPTY_TILE);
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

bool Maze::checkWinningMove(std::shared_ptr<MazeCell> current, Direction d) {
	return winningRoom == current->getCoordinates() && winningDirection == d;
}

void Maze::setWinningMove(std::shared_ptr<MazeCell> startingRoom,
		uint32_t seed) {
	auto coords = startingRoom->getCoordinates();
	std::map<Direction, uint16_t> distances = {
			{ Direction::N, coords.row },
			{ Direction::S, getLastRowIndex() - coords.row },
			{ Direction::W, coords.col },
			{ Direction::E, getLastColumnIndex() - coords.col },
	};

	using pair_type = decltype(distances)::value_type;
	winningDirection = std::max_element(distances.begin(), distances.end(),
			[](const pair_type &p1, const pair_type &p2) -> bool {
				return p1.second < p2.second;
			})->first;

	std::mt19937 mt(seed);
	std::uniform_int_distribution<> dis;

	switch (winningDirection) {
	case Direction::N:
		dis = std::uniform_int_distribution<>(0, getLastColumnIndex());
		winningRoom = Coordinates(dis(mt), 0);
		break;
	case Direction::S:
		dis = std::uniform_int_distribution<>(0, getLastColumnIndex());
		winningRoom = Coordinates(dis(mt), getLastColumnIndex());
		break;
	case Direction::W:
		dis = std::uniform_int_distribution<>(0, getLastRowIndex());
		winningRoom = Coordinates(0, dis(mt));
		break;
	default:
		dis = std::uniform_int_distribution<>(0, getLastRowIndex());
		winningRoom = Coordinates(getLastColumnIndex(), dis(mt));
		break;
	}
}

std::ostream& operator<<(std::ostream &outs, Maze &m) {
	for (uint16_t j = 0; j < m.getWidth() * 2 + 1; ++j)
		outs << "##";
	outs << "\n";

	for (uint16_t i = 0; i < m.getHeight(); ++i) {
		outs << "##";
		for (uint16_t j = 0; j < m.getWidth(); ++j) {
			auto cell = m(i, j);
			outs << "  "
					<< (cell->hasNeighbourInDirection(Direction::E) ? "  " : "##");
		}
		outs << "\n" << "##";
		for (uint16_t j = 0; j < m.getWidth(); ++j) {
			auto cell = m(i, j);
			outs << (cell->hasNeighbourInDirection(Direction::S) ? "  " : "##")
					<< "##";
		}
		outs << "\n";
	}
	outs << std::endl;

	return outs;
}