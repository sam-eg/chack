#ifndef CHACK_RANDO_H
#define CHACK_RANDO_H


#include "ActiveObject.h"
#include "../Level.h"

class Rando : public ActiveObject {

	Position movedPosition() const;
public:
	explicit Rando(const Position &position);

	void act(Player &player, const Level &level) override;
};


#endif //CHACK_RANDO_H
