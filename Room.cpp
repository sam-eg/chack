//
// Created by Sam Evans-Golden on 12/3/22.
//

#include "Room.h"
#include "objects/Wall.h"

Room::Room(int horizontalSize, int verticalSize, const Position &offset) : horizontalSize(horizontalSize),
																		   verticalSize(verticalSize), offset(offset) {}

void Room::init(std::vector<Object> &objects) {
	addWalls(objects);
}

void Room::addWalls(std::vector<Object> &objects) const {

	objects.emplace_back(Wall(Wall::CORNER, Position(0, 0) + offset));
	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back(Wall(Wall::HORIZONTAL, Position(0, i) + offset));
	}
	objects.emplace_back(Wall(Wall::CORNER, Position(0, verticalSize - 1) + offset));

	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back(Wall(Wall::VERTICAL, Position(i, 0) + offset));
		objects.emplace_back(Wall(Wall::VERTICAL, Position(i, verticalSize - 1) + offset));
	}

	objects.emplace_back(Wall(Wall::CORNER, Position(horizontalSize - 1, 0) + offset));
	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back(Wall(Wall::HORIZONTAL, Position(horizontalSize - 1, i) + offset));
	}
	objects.emplace_back(Wall(Wall::CORNER, Position(horizontalSize - 1, verticalSize - 1) + offset));
}


