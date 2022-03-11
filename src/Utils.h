//============================================================================
// Name        : Utils.cpp
// Author      : Federico Carne 1059865
// Date		   : 11 mar 2022
// Description : 
//============================================================================

#include <cstdlib>

void clear_screen() {
#ifdef _WINDOWS
    std::system("cls");
#else
	// Assume POSIX
	std::system("clear");
#endif
}

