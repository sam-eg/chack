#include "Game.h"
#include "Terminal.h"
#include "Player.h"

int main() {
	Terminal terminal(5, 5);

	Player player = Player('@', 0, 0);

	Level level = Level(20, 20, terminal, player);

	Game game(level, terminal, player);

	game.start();
	return 0;
}
