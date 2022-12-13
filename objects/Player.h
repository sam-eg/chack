//
// Created by Sam Evans-Golden on 11/23/22.
//

#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

#include <vector>
#include "Object.h"

class Player : public Object {
	int levelIndex = 0;
	bool won = false;
	std::vector<Object> inventory;

public:
	Player(const Position &position, int levelIndex);

	int getLevelIndex() const;

	void setLevelIndex(int levelIndex);

	bool didWin() const;

	void setWon(bool didWin);

	void addToInventory(const Object &object);

	bool hasInInventory(ObjectType type);
};


#endif //CHACK_PLAYER_H
