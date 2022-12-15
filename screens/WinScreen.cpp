//
// Created by Sam Evans-Golden on 12/8/22.
//

#include "WinScreen.h"

void WinScreen::display(const Player &player, Terminal &terminal) {
	terminal.display("You won!", Position {5, terminal.cols() / 2 - 4});

	char buffer[128];
	snprintf(buffer, 128, "You got %d coins.", player.getCoins());
	terminal.display(buffer, Position {7, terminal.cols() / 2 - 7});
}
