//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_GAME_H
#define CHACK_GAME_H

#include <vector>
#include "Level.h"
#include "Terminal.h"
#include "Player.h"
#include "Command.h"

class Game {
	std::vector<Level> levels;
	Player player;

	void init();
	static Command parse(char input);
	void processCommand(Command command);
	void movePlayer(const Position &delta);

public:

	Game();

	void play(Terminal &terminal);

};


#endif //CHACK_GAME_H
