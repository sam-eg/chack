#ifndef CHACK_GAME_H
#define CHACK_GAME_H

#include <vector>
#include "Level.h"
#include "Terminal.h"
#include "objects/Player.h"
#include "Command.h"

class Game {
	std::vector<Level> levels;
	Player player{Position(0, 0), 0};

	void init();
	static Command parse(int input);
	Position computeNewPlayerPosition(Command command);
	void movePlayerIfPossible(const Position &newPosition, const Object *objectAtPosition, Level &level);
	void processPlayerInteraction(const Object *object, Level &level);
	static void showTitle(Terminal &terminal);
	void mainLoop(Terminal &terminal);
	void showWinScreen(Terminal &terminal);
	void showLoseScreen(Terminal &terminal);
public:

	Game();

	void play(Terminal &terminal);

};


#endif //CHACK_GAME_H
