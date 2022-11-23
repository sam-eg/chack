//
// Created by Sam Evans-Golden on 11/23/22.
//

#ifndef CHACK_PLAYER_H
#define CHACK_PLAYER_H

class Player {
	char displayChar;
	int row;
	int col;

public:

	Player(char displayChar, int row, int col);

	char getDisplayChar() const;

	int getRow() const;

	int getCol() const;
};


#endif //CHACK_PLAYER_H
