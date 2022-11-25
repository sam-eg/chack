#include "Game.h"
#include "Terminal.h"

int main() {
	Terminal terminal;
	Game game;

	game.start(terminal);

	return 0;
}
