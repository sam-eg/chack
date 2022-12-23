#include "Rando.h"

Rando::Rando(const Position &position) : ActiveObject('R', position, ObjectType::RANDO) {}

void Rando::act(Player &player, const Level &level) {
	Position newPosition = movedPosition();
	auto objectAtPosition = level.getObjectAt(newPosition);
	if (player.getPosition() == newPosition) {
		player.kill();
	}
	if (!objectAtPosition || objectAtPosition->getType() != ObjectType::WALL) {
		setPosition(newPosition);
	}
}

Position Rando::movedPosition() const {
	int direction = rand() % 4;
	switch (direction) {
		case 0 : return getPosition() + Position(1, 0);
		case 1 : return getPosition() + Position(-1, 0);
		case 2 : return getPosition() + Position(0, 1);
		case 3 : return getPosition() + Position(0, -1);
		default: return getPosition();
	}
}
