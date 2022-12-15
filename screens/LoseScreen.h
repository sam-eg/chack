//
// Created by Sam Evans-Golden on 12/8/22.
//

#ifndef CHACK_LOSESCREEN_H
#define CHACK_LOSESCREEN_H


#include "../Terminal.h"
#include "../objects/Player.h"

class LoseScreen {
public:
	void display(const Player &player, Terminal &terminal);
};


#endif //CHACK_LOSESCREEN_H
