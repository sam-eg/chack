#ifndef CHACK_BOUNCER_H
#define CHACK_BOUNCER_H


#include "ActiveObject.h"

class Bouncer : public ActiveObject {
public:
	explicit Bouncer(const Position &position);

	void act(Player &player, const Level &level) override;
};


#endif //CHACK_BOUNCER_H
