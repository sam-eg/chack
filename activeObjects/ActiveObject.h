#ifndef CHACK_ACTIVEOBJECT_H
#define CHACK_ACTIVEOBJECT_H


#include "../objects/Object.h"
#include "../objects/Player.h"

class Level;

class ActiveObject : public Object {
public:
	ActiveObject(char displayCharacter, const Position &position, ObjectType type);

	virtual void act(Player &player, const Level &level) = 0;
};


#endif //CHACK_ACTIVEOBJECT_H
