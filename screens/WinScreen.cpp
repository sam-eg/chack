//
// Created by Sam Evans-Golden on 12/8/22.
//

#include "WinScreen.h"

void WinScreen::display(Terminal &terminal) {
	terminal.display("You won!", Position {5, terminal.cols() / 2 - 4});
}
