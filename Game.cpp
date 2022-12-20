#include <curses.h>
#include "Game.h"
#include "Command.h"
#include "screens/Title.h"
#include "screens/WinScreen.h"
#include "screens/LoseScreen.h"
#include "objects/Obstacle.h"
#include "objects/Goal.h"
#include "objects/Door.h"
#include "objects/Key.h"
#include "objects/Coin.h"
#include "objects/UpStairs.h"
#include "objects/DownStairs.h"

Game::Game() {
	init();
}

void Game::init() {
	Level levelOne {"one"};
	levelOne.addRoom(10, 7, Position(0, 0));
	levelOne.addRoom(7, 10, Position(2, 10));
	levelOne.addHorizontalHall(5, Position(5, 6));

	levelOne.putObject(new Obstacle(Position(2, 2)));
	levelOne.putObject(new Door(Position(6, 6)));
	levelOne.putObject(new Key(Position(8, 4)));
	levelOne.putObject(new Coin(Position(3, 13), 3));
	levelOne.putObject(new Coin(Position(7, 2), 5));
	levelOne.putObject(new DownStairs(Position(6, 17)));

	levels.push_back(std::move(levelOne));

	Level levelTwo {"two"};
	levelTwo.addRoom(20, 20, Position(0, 0));

	levelTwo.putObject(new UpStairs(Position(6, 17)));
	levelTwo.putObject(new Goal(Position(18, 18)));

	levels.push_back(std::move(levelTwo));

	player.setPosition(Position(1, 1));
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

		terminal.setOffset({0, 0});
		char buffer[128];
		snprintf(buffer, 128, "Coins: %d", player.getCoins());
		terminal.display(buffer, Position {1, 0});

		if (player.hasInInventory(ObjectType::KEY)) {
			terminal.display("Key", Position {2, 0});
		}

		terminal.setOffset({4, 0});
		Level &level = levels.at(player.getLevelIndex());

		level.display(terminal);

		player.display(terminal);

		terminal.refreshScreen();

		int input = terminal.read();
		Command command = parse(input);

		Position newPlayerPosition = computeNewPlayerPosition(command);
		auto objectAtPosition = level.getObjectAt(newPlayerPosition);

		movePlayerIfPossible(newPlayerPosition, objectAtPosition, level);
		bool gameRunning = processPlayerInteraction(objectAtPosition, level);

		if (command == Command::QUIT || !gameRunning) {
			break;
		}
	} while (true);
}

void Game::showWinScreen(Terminal &terminal) {
	terminal.clearScreen();
	WinScreen winScreen;
	winScreen.display(player, terminal);
	terminal.read();
}

void Game::showLoseScreen(Terminal &terminal) {
	terminal.clearScreen();
	LoseScreen loseScreen;
	loseScreen.display(player, terminal);
	terminal.read();
}

void Game::movePlayerIfPossible(const Position &newPosition, const Object *objectAtPosition, Level &level) {
	if (!objectAtPosition) {
		player.setPosition(newPosition);
		return;
	}

	if (objectAtPosition->getType() == ObjectType::DOOR) {
		if (player.hasInInventory(ObjectType::KEY)) {
			level.deleteObjectAt(objectAtPosition->getPosition());
		}
	} else if (objectAtPosition->getType() == ObjectType::DOWNSTAIRS) {
		player.setLevelIndex(player.getLevelIndex() + 1);
	} else if (objectAtPosition->getType() == ObjectType::UPSTAIRS) {
		player.setLevelIndex(player.getLevelIndex() - 1);
	} else if (objectAtPosition->getType() != ObjectType::WALL) {
		player.setPosition(newPosition);
	}
}

bool Game::processPlayerInteraction(const Object *object, Level &level) {
	if (!object) {
		return true;
	}

	if (object->getType() == ObjectType::GOAL) {
		player.setWon(true);
		return false;
	} else if (object->getType() == ObjectType::OBSTACLE) {
		return false;
	} else if (object->getType() == ObjectType::KEY) {
		auto key = level.deleteObjectAt(object->getPosition());
		if (key) {
			player.addToInventory(key);
		}
	} else if (object->getType() == ObjectType::COIN) {
		auto coinObject = level.deleteObjectAt(object->getPosition());
		if (coinObject) {
			const Coin *coin = dynamic_cast<Coin *>(coinObject.get());
			if (coin) {
				player.addToCoins(coin->getAmount());

			}
		}
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
