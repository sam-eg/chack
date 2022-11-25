//
// Created by Sam Evans-Golden on 11/23/22.
//

#include "Player.h"

Player::Player() = default;

char Player::getDisplayChar() const {
	return displayChar;
}

const Position &Player::getPosition() const {
	return position;
}

int Player::getLevelIndex() const {
	return levelIndex;
}

void Player::setLevelIndex(int newIndex) {
	Player::levelIndex = newIndex;
}

void Player::display(Terminal &terminal) const {
	terminal.display(getDisplayChar(), getPosition());
}
