//
// Created by Sam Evans-Golden on 11/21/22.
//

#include <curses.h>
#include "Game.h"
#include "objects/Player.h"
#include "Command.h"
#include "screens/Title.h"
#include "screens/WinScreen.h"
#include "screens/LoseScreen.h"

Game::Game() {
	init();
}

void Game::init() {
	Level levelOne {"one"};
	levelOne.addRoom(20, 20, Position(5, 5));
	levelOne.addObstacle(Position(7, 7));
	levelOne.addGoal(Position(23, 23));

	levels.push_back(levelOne);

	player.setPosition(Position(6, 6));
}

void Game::play(Terminal &terminal) {
	showTitle(terminal);
	mainLoop(terminal);

	if (player.didWin()) {
		showWinScreen(terminal);
	} else {
		showLoseScreen(terminal);
	}
}

void Game::showTitle(Terminal &terminal) {
	terminal.clearScreen();
	Title::display(terminal);
	terminal.read();
}

void Game::mainLoop(Terminal &terminal) {
	do {
		terminal.clearScreen();

		Level &level = levels.at(player.getLevelIndex());

		level.display(terminal);

		player.display(terminal);

		terminal.refreshScreen();

		int input = terminal.read();
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

void Game::showWinScreen(Terminal &terminal) {
	terminal.clearScreen();
	WinScreen::display(terminal);
	terminal.read();
}

void Game::showLoseScreen(Terminal &terminal) {
	terminal.clearScreen();
	LoseScreen::display(terminal);
	terminal.read();
}

void Game::movePlayerIfPossible(const Position &newPosition, const Object &objectAtPosition) {
	if (objectAtPosition.getType() != ObjectType::WALL) {
		player.setPosition(newPosition);
	}
}

bool Game::processPlayerInteraction(const Object &object) {
	if (object.getType() == ObjectType::GOAL) {
		player.setWon(true);
		return false;
	} else if (object.getType() == ObjectType::OBSTACLE) {
		return false;
	}

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

Command Game::parse(int input) {
	switch (input) {
		case 'q':
		case 0x1b: // esc
			return Command::QUIT;
		case KEY_UP: // up arrow
		case 'w':
			return Command::UP;
		case KEY_DOWN: // down arrow
		case 's':
			return Command::DOWN;
		case KEY_LEFT: // left arrow
		case 'a':
			return Command::LEFT;
		case KEY_RIGHT: // right arrow
		case 'd':
			return Command::RIGHT;
		default:
			return Command::OTHER;
	}
}
