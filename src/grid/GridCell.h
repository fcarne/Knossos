//============================================================================
// Name        : GridCell.h
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : Cell class & Direction enum definition
//============================================================================

#ifndef MAZE_GRIDCELL_H_
#define MAZE_GRIDCELL_H_

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <algorithm>

#include <grid/Coordinates.h>
#include <grid/Direction.h>

template<typename CellContent> class Grid;

template<typename Content>
class GridCell {
private:
	Coordinates coordinates;
	bool visited;
	std::shared_ptr<Content> content;
	std::unordered_map<Direction, std::weak_ptr<GridCell>> connectedNeighbours;

	friend class Grid<Content> ;
public:
	GridCell(uint16_t row, uint16_t col, const Content &initValue) :
			coordinates(col, row), visited(false) {
		content = std::make_shared<Content>(initValue);
	}
	~GridCell() = default;

	Coordinates getCoordinates() {
		return coordinates;
	}

	uint16_t getRow() {
		return coordinates.row;
	}
	uint16_t getCol() {
		return coordinates.col;
	}

	bool isVisited() {
		return visited;
	}
	void setVisited(bool visited) {
		this->visited = visited;
	}

	std::shared_ptr<Content> getContent() {
		return content;
	}

	std::unordered_map<Direction, std::weak_ptr<GridCell>> getNeighbours() {
		return connectedNeighbours;
	}

	bool hasNeighbourInDirection(Direction d) {
		return !(connectedNeighbours.find(d) == connectedNeighbours.end());
	}

	std::shared_ptr<GridCell> getNeighbour(Direction d) {
		if (hasNeighbourInDirection(d))
			return connectedNeighbours.at(d).lock();
		else
			return nullptr;
	}

	std::vector<Direction> getNeighboursDirection() {
		std::vector<Direction> directions;

		std::transform(
		    connectedNeighbours.begin(),
		    connectedNeighbours.end(),
		    std::back_inserter(directions),
		    [](const std::pair<Direction, std::weak_ptr<GridCell>> &pair){return pair.first;});

		return directions;
	}

	void addNeighbour(Direction d, const std::shared_ptr<GridCell> neighbour) {
		connectedNeighbours.insert( { d, neighbour });
	}

	void removeNeighbour(Direction d) {
		connectedNeighbours.erase(d);
	}

	friend std::ostream& operator<<(std::ostream &outs, GridCell p) {
		return outs << "(" << p.getRow() << ", " << p.getCol() << ", "
				<< static_cast<bool>(p.isVisited()) << ")";
	}
};

#endif /* MAZE_GIRDCELL_H_ */
