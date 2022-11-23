//
// Created by Sam Evans-Golden on 11/21/22.
//

#ifndef CHACK_SIZE_H
#define CHACK_SIZE_H


class Size {
	int rows;
	int cols;

public:
	Size(int rows, int cols);

	int getRows() const;

	int getCols() const;
};


#endif //CHACK_SIZE_H
