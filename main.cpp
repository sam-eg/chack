#include "Game.h"
#include "Terminal.h"

int main() {
	Size levelSize = Size(20, 20);
	Position offset = Position(5, 5);
	Terminal terminal;
	Level level = Level(levelSize, offset, terminal);

	Game game(level, terminal);

	game.start();
	return 0;
}
