//
// Created by Sam Evans-Golden on 11/23/22.
//

#include "Player.h"

Player::Player(char displayChar) : displayChar(displayChar) {}

char Player::getDisplayChar() const {
	return displayChar;
}
