//
// Created by Sam Evans-Golden on 11/26/22.
//

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

	void display(Terminal &terminal) const;

	int getDisplayCharacter() const;

	const Position &getPosition() const;

	ObjectType getType() const;

	void setPosition(const Position &position);
};


#endif //CHACK_OBJECT_H
