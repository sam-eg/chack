#ifndef CHACK_WINSCREEN_H
#define CHACK_WINSCREEN_H


#include "../Terminal.h"
#include "../objects/Player.h"

class WinScreen {
public:
	void display(const Player &player, Terminal &terminal);
};


#endif //CHACK_WINSCREEN_H
