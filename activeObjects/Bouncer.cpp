#include "Bouncer.h"

Bouncer::Bouncer(const Position &position, Direction direction) : ActiveObject('B', position, ObjectType::BOUNCER), direction(direction) {}

void Bouncer::act(Player &player, const Level &level) {
	Position newPosition = movedPosition();
	auto objectAtPosition = level.getObjectAt(newPosition);
	if (player.getPosition() == newPosition) {
		player.kill();
	}
	if (objectAtPosition && (objectAtPosition->getType() == ObjectType::WALL || objectAtPosition->getType() == ObjectType::DOOR)) {
		forward = !forward;
	} else {
		setPosition(newPosition);
	}
}

Position Bouncer::movedPosition() const {
	switch(direction) {
		case HORIZONTAL:
			return getPosition() + Position(0, forward ? 1 : -1);
		case VERTICAL:
			return getPosition() + Position(forward ? 1 : -1, 0);
	}
}