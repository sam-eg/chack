//
// Created by Sam Evans-Golden on 11/21/22.
//

#include <curses.h>
#include "Game.h"
#include "Player.h"

Game::Game(const Level &level, const Terminal &terminal, const Player &player) : level(level), terminal(terminal), player(player) {}

const Level &Game::getLevel() const {
	return level;
}

void Game::start() {
	level.display();

	getch();
}
