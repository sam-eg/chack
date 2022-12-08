//
// Created by Sam Evans-Golden on 12/8/22.
//

#include "LoseScreen.h"

void LoseScreen::display(Terminal &terminal) {
	terminal.display("You lose!", Position {5, terminal.cols() / 2 - 4});
}
