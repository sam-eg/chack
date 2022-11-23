#include "Game.h"
#include "Terminal.h"

int main() {
	Size levelSize = Size(20, 20);
	Position offset = Position(5, 5);
	Terminal terminal(offset);
	Level level = Level(levelSize, terminal);

	Game game(level, terminal);

	game.start();
	return 0;
}
