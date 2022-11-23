//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_TERMINAL_H
#define CHACK_TERMINAL_H

#include "Position.h"

class Terminal {
	Position offset;
public:
	explicit Terminal(const Position &offset);

	virtual ~Terminal();

	void clearScreen();
	void display(char character, Position position);
};


#endif //CHACK_TERMINAL_H
