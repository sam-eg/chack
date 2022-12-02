//
// Created by Sam Evans-Golden on 12/2/22.
//

#ifndef CHACK_WALL_H
#define CHACK_WALL_H


#include "Object.h"

class Wall : public Object {
public:
	enum WallType {
		HORIZONTAL = '=', VERTICAL = '|', CORNER = '+'
	};
	Wall(WallType type, const Position &position);
};


#endif //CHACK_WALL_H
