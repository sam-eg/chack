#include "Title.h"

void Title::display(Terminal &terminal) {
	terminal.display("CHack", Position {5, terminal.cols() / 2 - 2});
	terminal.display("Arrow keys or WASD to move", Position {7, terminal.cols() / 2 - 13});
	terminal.display("Press any key to start", Position {9, terminal.cols() / 2 - 11});
}
