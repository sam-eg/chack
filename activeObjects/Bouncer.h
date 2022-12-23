#ifndef CHACK_BOUNCER_H
#define CHACK_BOUNCER_H


#include "ActiveObject.h"
#include "../Level.h"

class Bouncer : public ActiveObject {
	bool forward = true;

	Position movedPosition() const;
public:
	enum Direction {
		HORIZONTAL,
		VERTICAL
	};

	explicit Bouncer(const Position &position, Direction direction);

	void act(Player &player, const Level &level) override;
private:
	Direction direction;
};


#endif //CHACK_BOUNCER_H
