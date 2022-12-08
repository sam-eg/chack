//
// Created by Sam Evans-Golden on 11/23/22.
//

#include "Player.h"


int Player::getLevelIndex() const {
	return levelIndex;
}

void Player::setLevelIndex(int newIndex) {
	Player::levelIndex = newIndex;
}

Player::Player(const Position &position, int levelIndex) : Object('@', position, ObjectType::PLAYER), levelIndex(levelIndex) {}

bool Player::didWin() const {
	return won;
}

void Player::setWon(bool didWin) {
	Player::won = didWin;
}
