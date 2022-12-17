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

	void display(const char *string, const Position &position);

	int read();

	int rows();

	int cols();
};


#endif //CHACK_TERMINAL_H
