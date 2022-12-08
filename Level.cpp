//
// Created by Sam Evans-Golden on 11/21/22.
//

#include "Level.h"
#include "Terminal.h"
#include "objects/Wall.h"
#include "objects/Goal.h"
#include "objects/Obstacle.h"

Level::Level(const std::string &name) : name(name) {
	init();
}

void Level::init() {
	createRooms();
	createGoal();
	createObstacles();
}

void Level::display(Terminal &terminal) {
	for (Object object : objects) {
		object.display(terminal);
	}
}
void Level::createRooms() {
	Room room = Room(20, 20, Position(0, 0));
	room.init(objects);

	rooms.push_back(room);
}

void Level::createObstacles() {
	putObject(Obstacle(Position(2, 3)));
	putObject(Obstacle(Position(5, 4)));
	putObject(Obstacle(Position(5, 7)));
	putObject(Obstacle(Position(7, 1)));
	putObject(Obstacle(Position(7, 10)));
	putObject(Obstacle(Position(7, 15)));
	putObject(Obstacle(Position(9, 5)));
	putObject(Obstacle(Position(10, 2)));
	putObject(Obstacle(Position(10, 10)));
	putObject(Obstacle(Position(10, 18)));
	putObject(Obstacle(Position(11, 3)));
	putObject(Obstacle(Position(13, 7)));

}

void Level::createGoal() {
	putObject(Goal(Position(18, 18)));
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