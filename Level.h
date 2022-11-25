//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include <string>
#include "Terminal.h"
#include "Player.h"
#include "Position.h"

class Level {
	std::string name;
	int horizontalSize;
	int verticalSize;
	Position offset;

	void printBorderRow(int row, Terminal &terminal) const;
	void printInteriorRow(int row, Terminal &terminal) const;

public:
	Level(const std::string &name, int horizontalSize, int verticalSize, const Position &offset);

	void display(Terminal &terminal);

	const Position &getOffset() const;

	int getHorizontalSize() const;

	int getVerticalSize() const;
};


#endif //CHACK_LEVEL_H
