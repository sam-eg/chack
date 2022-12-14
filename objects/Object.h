#ifndef CHACK_OBJECT_H
#define CHACK_OBJECT_H


#include "../Position.h"
#include "ObjectType.h"
#include "../Terminal.h"

class Object {
	int displayCharacter;
	Position position;
	ObjectType type;

public:
	Object(char displayCharacter, const Position &position, ObjectType type);
	virtual ~Object() = default;

	void display(Terminal &terminal) const;

	int getDisplayCharacter() const;

	const Position &getPosition() const;

	ObjectType getType() const;

	void setPosition(const Position &position);
};


#endif //CHACK_OBJECT_H
