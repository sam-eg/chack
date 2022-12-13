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

class Level {
	std::string name;
	std::vector<Object> objects;

public:
	explicit Level(const std::string &name);

	void display(Terminal &terminal);

	Object getObjectAt(const Position &position) const;

	void putObject(const Object &object);

	void deleteObjectAt(const Position &position);

	void addRoom(int horizontalSize, int verticalSize, const Position &position);

	void addHorizontalHall(int length, const Position &position);

	void addVerticalHall(int length, const Position &position);
};


#endif //CHACK_LEVEL_H
