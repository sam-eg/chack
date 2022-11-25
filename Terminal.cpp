//
// Created by Sam Evans-Golden on 11/21/22.
//

#include <curses.h>
#include "Terminal.h"

Terminal::Terminal() {
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	clear();
	refresh();
}

Terminal::~Terminal() {
	endwin();
}

void Terminal::clearScreen() {
	clear();
}

void Terminal::setOffset(const Position &newOffset) {
	Terminal::offset = newOffset;
}

void Terminal::display(char character, const Position &position) {
	Position offsetPosition = position + offset;
	mvaddch(offsetPosition.getRow(), offsetPosition.getCol(), character);
}

char Terminal::read() {
	return getch();
}

void Terminal::refreshScreen() {
	refresh();
}
