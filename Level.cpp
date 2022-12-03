//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"
#include "objects/Wall.h"
#include "objects/Goal.h"

Level::Level(const std::string &name) : name(name) {
	init();
}

void Level::init() {
	createRooms();
	createGoal();
}

void Level::display(Terminal &terminal) {
	for (Object object : objects) {
		object.display(terminal);
	}
}
void Level::createRooms() {
	Room room = Room(20, 20, Position(5, 5));
	room.init(objects);

	rooms.push_back(room);
}

void Level::createGoal() {
	putObject(Goal(Position(12, 12)));
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
