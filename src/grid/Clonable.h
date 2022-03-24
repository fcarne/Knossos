//============================================================================
// Name        : Clonable.h
// Author      : Federico Carne 1059865
// Date		   : 23 mar 2022
// Description : 
//============================================================================
#ifndef GRID_CLONABLE_H_
#define GRID_CLONABLE_H_

#include <memory>

template<class T>
class Clonable {
public:
	virtual std::shared_ptr<T> clone() = 0;
	virtual ~Clonable() = default;
};

#endif /* GRID_CLONABLE_H_ */
