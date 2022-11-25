//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"

Level::Level(const std::string &name, int horizontalSize, int verticalSize, const Position &offset) :
	name(name), horizontalSize(horizontalSize), verticalSize(verticalSize), offset(offset) {}

void Level::display(Terminal &terminal) {
	printBorderRow(-1, terminal);

	for (int i = 0; i < horizontalSize; i++) {
		printInteriorRow(i, terminal);
	}

	printBorderRow(horizontalSize, terminal);
}

void Level::printBorderRow(int row, Terminal &terminal) const {
	terminal.display('+', Position(row, -1));
	for (int i = 0; i < verticalSize; i++) {
		terminal.display('=', Position(row, i));
	}
	terminal.display('+', Position(row, verticalSize));
}

void Level::printInteriorRow(int row, Terminal &terminal) const {
	terminal.display('|', Position(row, -1));
	for (int i = 0; i < verticalSize; i++) {
		terminal.display('.', Position(row, i));
	}
	terminal.display('|', Position(row, verticalSize));
}

const Position &Level::getOffset() const {
	return offset;
}

int Level::getHorizontalSize() const {
	return horizontalSize;
}

int Level::getVerticalSize() const {
	return verticalSize;
}
