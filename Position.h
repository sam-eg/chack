//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_POSITION_H
#define CHACK_POSITION_H


class Position {
	int row;
	int col;
public:
	Position(int row, int col);

	int getRow() const;

	int getCol() const;
};


#endif //CHACK_POSITION_H
