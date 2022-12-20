#include "Level.h"
#include "Terminal.h"
#include "objects/Wall.h"

Level::Level(const std::string &name, int visibleRange) : name(name), visibleRange(visibleRange) {}

void Level::display(Terminal &terminal, const Position &playerPosition) {
	for (auto &object : objects) {
		if (shouldObjectDisplay(playerPosition, object->getPosition())) {
			object->display(terminal);
		}
	}
}

bool Level::shouldObjectDisplay(const Position &playerPosition, const Position &objectPosition) const {
	if (playerPosition.distance(objectPosition) <= visibleRange) {
		return true;
	}
	return false;
}

const Object *Level::getObjectAt(const Position &position) const {
	for (auto &object : objects) {
		if (position == object->getPosition()) return object.get();
	}
	return nullptr;
}

void Level::putObject(Object *object) {
	objects.push_back(std::unique_ptr<Object>(object));
}

std::unique_ptr<Object> Level::deleteObjectAt(const Position &position) {
	for (int i = 0; i < objects.size(); i++) {
		if (position == objects[i]->getPosition()) {
			std::unique_ptr<Object> temp = std::move(objects[i]);
			objects.erase(objects.begin() + i);
			return temp;
		}
	}
	return {nullptr};
}

void Level::addRoom(int horizontalSize, int verticalSize, const Position &position) {
	putObject(new Wall(Wall::CORNER, Position(0, 0) + position));
	putObject(new Wall(Wall::CORNER, Position(horizontalSize - 1, 0) + position));
	for (int i = 1; i < verticalSize - 1; i++) {
		putObject(new Wall(Wall::HORIZONTAL, Position(0, i) + position));
		putObject(new Wall(Wall::HORIZONTAL, Position(horizontalSize - 1, i) + position));
	}
	putObject(new Wall(Wall::CORNER, Position(0, verticalSize - 1) + position));
	putObject(new Wall(Wall::CORNER, Position(horizontalSize - 1, verticalSize - 1) + position));

	for (int i = 1; i < horizontalSize - 1; i++) {
		putObject(new Wall(Wall::VERTICAL, Position(i, 0) + position));
		putObject(new Wall(Wall::VERTICAL, Position(i, verticalSize - 1) + position));
	}

}

void Level::addHorizontalHall(int length, const Position &position) {
	int hallWidth = 3;
	for (int i = 0; i < hallWidth; i++) {
		deleteObjectAt(Position(i, 0) + position);
		deleteObjectAt(Position(i, length - 1) + position);
	}

	putObject(new Wall(Wall::CORNER, Position(0, 0) + position));
	putObject(new Wall(Wall::CORNER, Position(0, length - 1) + position));
	for (int i = 1; i < length - 1; i++) {
		putObject(new Wall(Wall::HORIZONTAL, Position(0, i) + position));
		putObject(new Wall(Wall::HORIZONTAL, Position(hallWidth - 1, i) + position));
	}
	putObject(new Wall(Wall::CORNER, Position(hallWidth - 1, 0) + position));
	putObject(new Wall(Wall::CORNER, Position(hallWidth - 1, length - 1) + position));
}

void Level::addVerticalHall(int length, const Position &position) {
	int hallWidth = 3;
	for (int i = 0; i < hallWidth; i++) {
		deleteObjectAt(Position(0, i) + position);
		deleteObjectAt(Position(length - 1, i) + position);
	}

	putObject(new Wall(Wall::CORNER, Position(0, 0) + position));
	putObject(new Wall(Wall::CORNER, Position(0, hallWidth - 1) + position));
	for (int i = 1; i < length - 1; i++) {
		putObject(new Wall(Wall::VERTICAL, Position(i, 0) + position));
		putObject(new Wall(Wall::VERTICAL, Position(i, hallWidth - 1) + position));
	}
	putObject(new Wall(Wall::CORNER, Position(length - 1, 0) + position));
	putObject(new Wall(Wall::CORNER, Position(length - 1, hallWidth - 1) + position));
}
