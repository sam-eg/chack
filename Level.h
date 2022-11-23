//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include "Terminal.h"
#include "Player.h"

class Level {
	int horizontalSize;
	int verticalSize;
	Terminal terminal;
	Player player;
	int playerRow;
	int playerCol;

	void printBorderRow(int row);
	void printInteriorRow(int row);
	void printPlayer(int row, int col);

public:

	Level(int horizontalSize, int verticalSize, const Terminal &terminal, const Player &player);

	void display();

};


#endif //CHACK_LEVEL_H
