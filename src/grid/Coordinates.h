//============================================================================
// Name        : Coordinates.h
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================
#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_

#include <cstdint>

struct Coordinates {
	uint16_t col;
	uint16_t row;

	Coordinates() :
			col(0), row(0) {
	}
	Coordinates(uint16_t col, uint16_t row) :
			col(col), row(row) {
	}

	bool operator==(Coordinates const &rhs) const {
		return col == rhs.col && row == rhs.row;
	}
};

#endif /* GRID_COORDINATES_H_ */
