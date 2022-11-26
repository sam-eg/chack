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
		movePlayer(command);
		bool gameRunning = processPlayerInteraction();

		if (command == Command::QUIT || !gameRunning) {
			break;
		}
	} while (true);
}

void Game::movePlayerIfPossible(const Position &delta) {
	Position newPosition = player.getPosition() + delta;
	Level &level = levels.at(player.getLevelIndex());
	Object objectAtPosition = level.getObjectAt(newPosition);

	if (objectAtPosition.getType() != ObjectType::WALL) {
		player.setPosition(newPosition);
	}
}

bool Game::processPlayerInteraction() {
	Level &level = levels.at(player.getLevelIndex());
	Object objectAtPosition = level.getObjectAt(player.getPosition());

	if (objectAtPosition.getType() == ObjectType::GOAL) return false;

	return true;
}

void Game::movePlayer(Command command) {
	switch (command) {
		case Command::UP:
			movePlayerIfPossible(Position(-1, 0));
			break;
		case Command::DOWN:
			movePlayerIfPossible(Position(1, 0));
			break;
		case Command::LEFT:
			movePlayerIfPossible(Position(0, -1));
			break;
		case Command::RIGHT:
			movePlayerIfPossible(Position(0, 1));
			break;
		case Command::QUIT:
		case Command::OTHER:
			break;
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
