//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include "Size.h"
#include "Terminal.h"

class Level {
	Size size;
	Terminal terminal;

	void printBorderRow(int row);

	void printInteriorRow(int row);

public:
	const Size &getSize() const;

	Level(const Size &size, const Terminal &terminal);

	void display();
};


#endif //CHACK_LEVEL_H
