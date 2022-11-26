//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"

Level::Level(const std::string &name, int horizontalSize, int verticalSize, const Position &offset) :
	name(name), horizontalSize(horizontalSize), verticalSize(verticalSize), offset(offset) {
	init();
}

void Level::init() {
	createWalls();
}

void Level::display(Terminal &terminal) {
	for (Object object : objects) {
		object.display(terminal);
	}
}

void Level::createWalls() {
	objects.emplace_back(Object('+', Position(0, 0), ObjectType::WALL));
	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back(Object('=', Position(0, i), ObjectType::WALL));
	}
	objects.emplace_back(Object('+', Position(0, verticalSize - 1), ObjectType::WALL));

	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back('|', Position(i, 0), ObjectType::WALL);
		objects.emplace_back('|', Position(i, verticalSize - 1), ObjectType::WALL);
	}

	objects.emplace_back(Object('+', Position(horizontalSize - 1, 0), ObjectType::WALL));
	for (int i = 1; i < horizontalSize - 1; i++) {
		objects.emplace_back(Object('=', Position(horizontalSize - 1, i), ObjectType::WALL));
	}
	objects.emplace_back(Object('+', Position(horizontalSize - 1, verticalSize - 1), ObjectType::WALL));
}

const Position &Level::getOffset() const {
	return offset;
}

int Level::getHorizontalSize() const {
	return horizontalSize;
}

int Level::getVerticalSize() const {
	return verticalSize;
}
