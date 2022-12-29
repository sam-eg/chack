#ifndef CHACK_COIN_H
#define CHACK_COIN_H


#include "Object.h"

class Coin : public Object {
	int amount;
public:
	Coin(const Position &position, int amount);

	int getAmount() const;
};


#endif //CHACK_COIN_H
