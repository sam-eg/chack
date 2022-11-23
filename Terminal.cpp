//
// Created by Sam Evans-Golden on 11/21/22.
//

#include <curses.h>
#include "Terminal.h"

Terminal::Terminal(int rowOffset, int colOffset) : rowOffset(rowOffset), colOffset(colOffset) {
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	clear();
}

Terminal::~Terminal() {
	endwin();
}

void Terminal::clearScreen() {
	clear();
	refresh();
}

void Terminal::display(char character, int row, int col) {
	mvaddch(rowOffset + row, colOffset + col, character);
	refresh();
}
