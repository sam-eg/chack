//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_GAME_H
#define CHACK_GAME_H

#include <vector>
#include "Level.h"
#include "Terminal.h"
#include "Player.h"

class Game {
	std::vector<Level> levels;
	Player player;

	void init();

public:

	Game();

	void start(Terminal &terminal);
};


#endif //CHACK_GAME_H
