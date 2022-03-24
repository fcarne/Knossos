//============================================================================
// Name        : GridCell_test.cpp
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : GridCell test
//============================================================================

#include <iostream>
#include <memory>

#include <grid/Direction.h>
#include <grid/GridCell.h>
#include <grid/Clonable.h>

class A: public Clonable<A> {
public:
	int x;
	double y;
	std::shared_ptr<A> clone() override {
		return std::make_shared<A>(*this);
	}
	~A() = default;
};

int main_gridcell_test() {
	GridCell<A> cell(1, 1, std::make_shared<A>());
	std::cout << cell << "\n";
	Direction d = Direction::E;
	std::cout << d.toString() << " --- " << d.opposite().toString()
			<< std::endl;
	return 0;
}

