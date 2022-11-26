//
// Created by Sam Evans-Golden on 11/23/22.
//

#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

#include "Position.h"
#include "Terminal.h"

class Player {
	char displayChar = '@';
	int levelIndex = 0;
	Position position {1, 1};

public:

	Player();

	char getDisplayChar() const;

	const Position &getPosition() const;

	int getLevelIndex() const;

	void setLevelIndex(int levelIndex);

	void setPosition(const Position &newPosition);

	void display(Terminal &terminal) const;
};


#endif //CHACK_PLAYER_H
