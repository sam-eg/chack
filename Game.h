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
	Player player{Position(1, 1), 0};

	void init();
	static Command parse(int input);
	Position computeNewPlayerPosition(Command command);
	void movePlayerIfPossible(const Position &newPosition, const Object &objectAtPosition);
	bool processPlayerInteraction(const Object &object);
public:

	Game();

	void play(Terminal &terminal);

};


#endif //CHACK_GAME_H
