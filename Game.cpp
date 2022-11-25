//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Game.h"
#include "Player.h"

Game::Game() {
	init();
}

void Game::init() {
	levels.emplace_back("test", 20, 20, Position(5, 5));
}

void Game::start(Terminal &terminal) {

	Level &level = levels.at(player.getLevelIndex());
	terminal.setOffset(level.getOffset());

	level.display(terminal);

	player.display(terminal);

	terminal.read();
}
