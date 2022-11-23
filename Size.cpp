//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Size.h"

Size::Size(int rows, int cols) : rows(rows), cols(cols) {}

int Size::getRows() const {
	return rows;
}

int Size::getCols() const {
	return cols;
}
