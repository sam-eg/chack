#ifndef CHACK_LEVEL_H
#define CHACK_LEVEL_H


#include <string>
#include <vector>
#include <memory>
#include "Terminal.h"
#include "Position.h"
#include "objects/Object.h"
#include "activeObjects/ActiveObject.h"

class Level {
	std::string name;
	std::vector<std::unique_ptr<Object>> objects;
	std::vector<std::unique_ptr<ActiveObject>> activeObjects;
	int visibleRange;

	bool shouldObjectDisplay(const Position &playerPosition, const Position &objectPosition) const;

public:
	Level(const std::string &name, int visibleRange);

	void display(Terminal &terminal, const Position &playerPosition);

	void tick(Player &player);

	const Object *getObjectAt(const Position &position) const;

	void putObject(Object *object);

	void putActiveObject(ActiveObject *object);

	std::unique_ptr<Object> deleteObjectAt(const Position &position);

	void addRoom(int horizontalSize, int verticalSize, const Position &position);

	void addHorizontalHall(int length, const Position &position);

	void addVerticalHall(int length, const Position &position);
};


#endif //CHACK_LEVEL_H
