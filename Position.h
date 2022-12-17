#ifndef CHACK_POSITION_H
#define CHACK_POSITION_H


class Position {
	int row = 0;
	int col = 0;
public:
	Position(int row, int col);

	int getRow() const;

	int getCol() const;

	Position operator+(const Position &other) const;

	bool operator==(const Position &other) const;
};


#endif //CHACK_POSITION_H
