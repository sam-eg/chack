//
// Created by Sam Evans-Golden on 11/23/22.
//

#include "Player.h"

Player::Player(char displayChar, int row, int col) : displayChar(displayChar), row(row), col(col) {}

char Player::getDisplayChar() const {
	return displayChar;
}

int Player::getRow() const {
	return row;
}

int Player::getCol() const {
	return col;
}
