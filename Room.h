//
// Created by Sam Evans-Golden on 12/3/22.
//

#ifndef CHACK_ROOM_H
#define CHACK_ROOM_H

#include <vector>
#include "Position.h"
#include "objects/Object.h"

class Room {
	int horizontalSize;
	int verticalSize;
	Position offset;

	void addWalls(std::vector<Object> &objects) const;

public:
	void init(std::vector<Object> &objects);

	Room(int horizontalSize, int verticalSize, const Position &offset);

};


#endif //CHACK_ROOM_H
