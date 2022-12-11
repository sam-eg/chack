//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"
#include "objects/Wall.h"
#include "objects/Goal.h"
#include "objects/Obstacle.h"

Level::Level(const std::string &name) : name(name) {}

void Level::display(Terminal &terminal) {
	for (Object object : objects) {
		object.display(terminal);
	}
}

Object Level::getObjectAt(const Position &position) const {
	for (Object object : objects) {
		if (position == object.getPosition()) return object;
	}
	return {' ', position, ObjectType::SPACE};
}

void Level::putObject(Object object) {
	objects.push_back(object);
}

void Level::deleteObjectAt(const Position &position) {
	for (int i = 0; i < objects.size(); i++) {
		if (position == objects.at(i).getPosition()) {
			objects.erase(objects.begin() + i);
			break;
		}
	}
}

void Level::addRoom(int horizontalSize, int verticalSize, const Position &position) {
	putObject(Wall(Wall::CORNER, Position(0, 0) + position));
	for (int i = 1; i < verticalSize - 1; i++) {
		putObject(Wall(Wall::HORIZONTAL, Position(0, i) + position));
	}
	putObject(Wall(Wall::CORNER, Position(0, verticalSize - 1) + position));

	for (int i = 1; i < horizontalSize - 1; i++) {
		putObject(Wall(Wall::VERTICAL, Position(i, 0) + position));
		putObject(Wall(Wall::VERTICAL, Position(i, verticalSize - 1) + position));
	}

	putObject(Wall(Wall::CORNER, Position(horizontalSize - 1, 0) + position));
	for (int i = 1; i < verticalSize - 1; i++) {
		putObject(Wall(Wall::HORIZONTAL, Position(horizontalSize - 1, i) + position));
	}
	putObject(Wall(Wall::CORNER, Position(horizontalSize - 1, verticalSize - 1) + position));

}

void Level::addObstacle(const Position &position) {
	putObject(Obstacle(position));
}

void Level::addGoal(const Position &position) {
	putObject(Goal(position));
}
