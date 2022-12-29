#include "Title.h"

void Title::display(Terminal &terminal) {
	terminal.display("CHack", Position {5, terminal.cols() / 2 - 2});
	terminal.display("Arrow keys or WASD to move. Q to quit", Position {7, terminal.cols() / 2 - 17});
	terminal.display("Pick up o - coins and F - keys for D - doors.", Position {9, terminal.cols() / 2 - 22});
	terminal.display("Don't run into enemies! X - trap, B - bouncer, and R - wanderer.", Position {11, terminal.cols() / 2 - 32});
	terminal.display("Use stairs ^ - up and v - down to find the P - flag to win!", Position {13, terminal.cols() / 2- 30});
	terminal.display("Press any key to start", Position {16, terminal.cols() / 2 - 11});
}
