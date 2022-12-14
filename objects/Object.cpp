#include "Object.h"

Object::Object(char displayCharacter, const Position &position, ObjectType type) :
	displayCharacter(displayCharacter), position(position), type(type) {}

void Object::display(Terminal &terminal) const {
	terminal.display(getDisplayCharacter(), getPosition());
}

int Object::getDisplayCharacter() const {
	return displayCharacter;
}

const Position &Object::getPosition() const {
	return position;
}

void Object::setPosition(const Position &newPosition) {
	Object::position = newPosition;
}

ObjectType Object::getType() const {
	return type;
}
