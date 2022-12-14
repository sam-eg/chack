#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

#include <memory>
#include <vector>
#include "Object.h"
#include "Coin.h"

class Player : public Object {
	int levelIndex = 0;
	bool won = false;
	std::vector<std::unique_ptr<Object>> inventory;
	int coins = 0;
	bool alive = true;

public:
	Player(const Position &position, int levelIndex);

	int getLevelIndex() const;

	void setLevelIndex(int levelIndex);

	bool didWin() const;

	void setWon(bool didWin);

	void addToInventory(std::unique_ptr<Object> &object);

	bool hasInInventory(ObjectType type);

	void addToCoins(int value);

	int getCoins() const;

	void kill();

	bool isAlive() const;
};


#endif //CHACK_PLAYER_H
