//============================================================================
// Name        : TimeTrial.h
// Author      : Federico Carne 1059865
// Date		   : 16 mar 2022
// Description : 
//============================================================================
#ifndef GAME_TIMETRIAL_H_
#define GAME_TIMETRIAL_H_

#include <game/GameMode.h>

class TimeTrial: public GameMode {
public:
	TimeTrial();
	void initGame() override;
	void play() override;
	void printDescription() override;
};

#endif /* GAME_TIMETRIAL_H_ */
