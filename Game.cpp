//
// Created by Sam Evans-Golden on 11/21/22.
//

#include <curses.h>
#include "Game.h"

Game::Game(const Level &level, const Terminal &terminal) : level(level), terminal(terminal) {}

const Level &Game::getLevel() const {
	return level;
}

void Game::start() {
	level.display();

	getch();
}
