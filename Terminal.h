//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_TERMINAL_H
#define CHACK_TERMINAL_H


class Terminal {
	int rowOffset;
	int colOffset;
public:
	explicit Terminal(int rowOffset, int colOffset);

	virtual ~Terminal();

	void clearScreen();
	void display(char character, int row, int col);
};


#endif //CHACK_TERMINAL_H
