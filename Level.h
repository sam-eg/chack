//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include <string>
#include <vector>
#include "Terminal.h"
#include "Position.h"
#include "objects/Object.h"
#include "Room.h"

class Level {
	std::string name;
	std::vector<Object> objects;
	std::vector<Room> rooms;

	void init();

	void createGoal();

	void createRooms();

public:
	explicit Level(const std::string &name);

	void display(Terminal &terminal);

	Object getObjectAt(const Position &position) const;

	void putObject(Object object);
};


#endif //CHACK_LEVEL_H
