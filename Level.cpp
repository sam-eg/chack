//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"
#include "Player.h"

Level::Level(int horizontalSize, int verticalSize, const Terminal &terminal, const Player &player) :
	horizontalSize(horizontalSize), verticalSize(verticalSize), terminal(terminal), player(player) {
	playerRow = 0;
	playerCol = 0;
}

void Level::display() {
	printBorderRow(-1);

	for (int i = 0; i < horizontalSize; i++) {
		printInteriorRow(i);
	}

	printBorderRow(horizontalSize);

	printPlayer(playerRow, playerCol);
}

void Level::printBorderRow(int row) {
	terminal.display('+', row, -1);
	for (int i = 0; i < verticalSize; i++) {
		terminal.display('=', row, i);
	}
	terminal.display('+', row, verticalSize);
}

void Level::printInteriorRow(int row) {
	terminal.display('|', row, -1);
	for (int i = 0; i < verticalSize; i++) {
		terminal.display('.', row, i);
	}
	terminal.display('|', row, verticalSize);
}

void Level::printPlayer(int row, int col) {
	terminal.display(player.getDisplayChar(), row, col);
}