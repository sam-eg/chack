//
// Created by Sam Evans-Golden on 12/8/22.
//

#include "LoseScreen.h"

void LoseScreen::display(const Player &player, Terminal &terminal) {
	terminal.display("You lose!", Position {5, terminal.cols() / 2 - 4});

	char buffer[128];
	snprintf(buffer, 128, "You had %d coins when you died.", player.getCoins());
	terminal.display(buffer, Position {7, terminal.cols() / 2 - 15});
}
