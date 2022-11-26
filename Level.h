//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include <string>
#include <vector>
#include "Terminal.h"
#include "Player.h"
#include "Position.h"
#include "Object.h"

class Level {
	std::vector<Object> objects;
	std::string name;
	int horizontalSize;
	int verticalSize;
	Position offset;

	void init();
	void createWalls();

public:
	Level(const std::string &name, int horizontalSize, int verticalSize, const Position &offset);

	void display(Terminal &terminal);

	const Position &getOffset() const;

	int getHorizontalSize() const;

	int getVerticalSize() const;

	Object getObjectAt(const Position &position) const;
};


#endif //CHACK_LEVEL_H
