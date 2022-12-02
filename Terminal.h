//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_TERMINAL_H
#define CHACK_TERMINAL_H


#include "Position.h"

class Terminal {
	Position offset{0, 0};
public:
	Terminal();

	virtual ~Terminal();

	void setOffset(const Position &newOffset);

	void clearScreen();

	void refreshScreen();

	void display(int character, const Position &position);

	int read();
};


#endif //CHACK_TERMINAL_H
