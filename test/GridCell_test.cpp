//============================================================================
// Name        : GridCell_test.cpp
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : GridCell test
//============================================================================

#include <iostream>

#include "../src/grid/GridCell.h"
#include "../src/grid/Directions.h"

class A {
	int x;
	double y;
};

int main_gridcell_test() {
	GridCell<A> cell(1, 1, A());
	std::cout << cell << "\n";
	Direction d = Direction::E;
	std::cout << d.toString() << " --- " << d.opposite().toString() <<std::endl;
	return 0;
}

