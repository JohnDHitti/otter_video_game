#include "Game.h"
#include <iostream>

int main()
{
	// INIT GAME ENGINE
	Game game;

	// Game Loop
	while (game.getWindowIsOpen())
	{
	
	
		// UPDATE
		game.update();

		// RENDER
		game.render();
	}
	return 0;
}

// Game documentation and comments located at the bottom of Game.h file