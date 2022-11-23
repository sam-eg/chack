//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"

Level::Level(const Size &size, const Position &offset, const Terminal &terminal) : size(size), offset(offset),
																				   terminal(terminal) {}

const Size &Level::getSize() const {
	return size;
}

void Level::display() {
	printBorderRow(-1);

	for (int i = 0; i < size.getRows(); i++) {
		printInteriorRow(i);
	}

	printBorderRow(size.getRows());
}

void Level::printBorderRow(int row) {
	terminal.display('+', Position(offset.getRow() + row, offset.getCol() + -1));
	for (int i = 0; i < size.getCols(); i++) {
		terminal.display('=', Position(offset.getRow() + row, offset.getCol() + i));
	}
	terminal.display('+', Position(offset.getRow() + row, offset.getCol() + size.getCols()));
}

void Level::printInteriorRow(int row) {
	terminal.display('|', Position(offset.getRow() + row, offset.getCol() + -1));
	for (int i = 0; i < size.getCols(); i++) {
		terminal.display('.', Position(offset.getRow() + row, offset.getCol() + i));
	}
	terminal.display('|', Position(offset.getRow() + row, offset.getCol() + size.getCols()));
}


