//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Game.h"
#include "Player.h"
#include "Command.h"

Game::Game() {
	init();
}

void Game::init() {
	levels.emplace_back("test", 20, 20, Position(5, 5));
}

void Game::play(Terminal &terminal) {

	do {
		terminal.clearScreen();

		Level &level = levels.at(player.getLevelIndex());
		terminal.setOffset(level.getOffset());

		level.display(terminal);

		player.display(terminal);

		terminal.refreshScreen();

		char input = terminal.read();
		Command command = parse(input);

		Position newPlayerPosition = computeNewPlayerPosition(command);
		Object objectAtPosition = level.getObjectAt(newPlayerPosition);

		movePlayerIfPossible(newPlayerPosition, objectAtPosition);
		bool gameRunning = processPlayerInteraction(objectAtPosition);

		if (command == Command::QUIT || !gameRunning) {
			break;
		}
	} while (true);
}

void Game::movePlayerIfPossible(const Position &newPosition, const Object &objectAtPosition) {
	Level &level = levels.at(player.getLevelIndex());

	if (objectAtPosition.getType() != ObjectType::WALL) {
		player.setPosition(newPosition);
	}
}

bool Game::processPlayerInteraction(const Object &object) {
	Level &level = levels.at(player.getLevelIndex());

	if (object.getType() == ObjectType::GOAL) return false;

	return true;
}

Position Game::computeNewPlayerPosition(Command command) {
	switch (command) {
		case Command::UP:
			return player.getPosition() + Position(-1, 0);
		case Command::DOWN:
			return player.getPosition() + Position(1, 0);
		case Command::LEFT:
			return player.getPosition() + Position(0, -1);
		case Command::RIGHT:
			return player.getPosition() + Position(0, 1);
		default:
			return player.getPosition();
	}
}

Command Game::parse(char input) {
	switch (input) {
		case 'q':
		//case 27: // esc
			return Command::QUIT;
		case 65: // up arrow
		case 'w':
			return Command::UP;
		case 66: // down arrow
		case 's':
			return Command::DOWN;
		case 68: //left arrow
		case 'a':
			return Command::LEFT;
		case 67: // right arrow
		case 'd':
			return Command::RIGHT;
		default:
			return Command::OTHER;
	}
}
