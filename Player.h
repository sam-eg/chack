//
// Created by Sam Evans-Golden on 11/23/22.
//

#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

#include "Position.h"
#include "Terminal.h"
#include "Object.h"

class Player : public Object {
	int levelIndex = 0;
public:
	Player(const Position &position, int levelIndex);

	int getLevelIndex() const;

	void setLevelIndex(int levelIndex);
	
};


#endif //CHACK_PLAYER_H
