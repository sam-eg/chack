//
// Created by Sam Evans-Golden on 11/23/22.
//

#include "Player.h"
#include "Coin.h"


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

void Player::addToInventory(std::unique_ptr<Object> &object) {
	inventory.push_back(std::move(object));
}

void Player::addToCoins(int value) {
	coins += value;
}

int Player::getCoins() const {
	return coins;
}

bool Player::hasInInventory(ObjectType objectType) {
	for (auto &item : inventory) {
		if (item->getType() == objectType) {
			return true;
		}
	}
	return false;
}
