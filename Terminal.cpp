#include <curses.h>
#include "Terminal.h"

Terminal::Terminal() {
	initscr();
	curs_set(0);
	cbreak();
	keypad(stdscr, true);
	set_escdelay(100);
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

void Terminal::display(int character, const Position &position) {
	Position offsetPosition = position + offset;
	mvaddch(offsetPosition.getRow(), offsetPosition.getCol(), character);
}

void Terminal::display(const char* string, const Position &position) {
	Position offsetPosition = position + offset;
	mvaddstr(offsetPosition.getRow(), offsetPosition.getCol(), string);
}

int Terminal::read() {
	return getch();
}

void Terminal::refreshScreen() {
	refresh();
}

int Terminal::rows() {
	return LINES;
}

int Terminal::cols() {
	return COLS;
}
