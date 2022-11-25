//
// Created by Sam Evans-Golden on 11/25/22.
//

#include "Position.h"

Position::Position(int row, int col) : row(row), col(col) {}

int Position::getRow() const {
	return row;
}

int Position::getCol() const {
	return col;
}

Position Position::operator+(const Position &other) const {
	return {row + other.getRow(), col + other.getCol()};
}
