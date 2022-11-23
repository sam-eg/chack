//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_GAME_H
#define CHACK_GAME_H

#include "Level.h"
#include "Terminal.h"
#include "Player.h"

class Game {
	Level level;
	Terminal terminal;
	Player player;

public:

	Game(const Level &level, const Terminal &terminal, const Player &player);

	const Level &getLevel() const;

	void start();
};


#endif //CHACK_GAME_H
