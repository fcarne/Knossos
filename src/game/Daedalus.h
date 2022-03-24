//============================================================================
// Name        : Daedalus.h
// Author      : Federico Carne 1059865
// Date		   : 24 mar 2022
// Description : 
//============================================================================
#ifndef GAME_DAEDALUS_H_
#define GAME_DAEDALUS_H_

#include <game/GameMode.h>

class Daedalus: public GameMode {
public:
	Daedalus();
	void initGame() override;
	bool play() override;
	void printDescription() override;
};

#endif /* GAME_DAEDALUS_H_ */
