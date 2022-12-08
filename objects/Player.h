//
// Created by Sam Evans-Golden on 11/23/22.
//

#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

#include "Object.h"

class Player : public Object {
	int levelIndex = 0;
	bool won = false;

public:
	Player(const Position &position, int levelIndex);

	int getLevelIndex() const;

	void setLevelIndex(int levelIndex);

	bool didWin() const;

	void setWon(bool didWin);
};


#endif //CHACK_PLAYER_H
