#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Level1.h"

/*
Class for game engine
*/
class Game
{
private:
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	// Mouse Positions
	sf::Vector2i mousePosWindow;
	// Game Logic
	bool start = false;
	// Game Objects
	Level1 Level1;
	// Private Functions
	void initVar();
	void initWindow();
	void startScreen();
	// Game Screens
	sf::Sprite gameOverScreen;
	sf::Sprite gameCompletionScreen;
	sf::Sprite gameStartScreen;
	sf::Sprite gameStartScreenbg;
	sf::Texture gameOverScreenTexture;
	sf::Texture gameCompletionScreenTexture;
	sf::Texture gameStartScreenTexture;
	sf::Texture gameStartScreenTexturebg;
	void initScreens();
	void updateGameOverScreen();
	void updateGameCompletionScreen();
	void updateGameStartScreen();
	void renderGameOverScreen();
	void renderGameCompletionScreen();
	void renderGameStartScreen();
	bool gameOver = false;
	bool gameComplete = false;
	sf::Clock screenAnimationClock;// clock for controlling animation (currently unused)
public:
	// Constructors/Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool getWindowIsOpen() const;

	// Functions
	void pollEvents();
	void updateMousePositions();
	void update();
	void render();
};

/*
Game Structure Notes:
The game is organized into classes. Although it may seem overcomplicated currently I designed the code this way to expand easier and make the generation of new "levels" easer. A lot of the work here was creating the engine and making easy to build on. 


The game class is responsable for menu functions and the window functions.
The actual level of the game is located in the level1 class and is where most of the games functions reside as well as the construction of the level. 
From there each class is responsable for an aspect of the game. The level1 class calls all the functions, updates, and renders for these clases.

Chunk: Responsable for genererating the forground terrain. Each chunk contains 3 base platforms and a variety of foliage and sky platforms.
Platform: Generates sky platforms within each chunk. these can be set manually in the Level1.cpp
Foliage: Generates foliage in the chunk class. Currently this is random with some set limits.
Otter: Generates the otter and dictates his behavior and animation
Polling: Updates the users keyboard input. Values from this class is sent to the update functions to update the game according to the users input
Physics: A general physics system with velocity, acceleration, position, gravitry effects, and more. Responsible for otters movements
Collision: A class to deteck when two things are colliding and from what side they are colliding. Currently it is used to detect when whe otter hits a platfrom.


Unused classes--------
Bee: used for the future bee character
Rabbit: used for the future rabbit charater
Menu: used to clean up the game.cpp and add menu functionality to a specific class


Here is a quick diagram of how the update and render functions are called: 

                  (game)
				     |
                 (level 1)
				 /      \
              (otter) (chunk)
			          /     \
                 (foliage)(platfoms)

*/






/*
Notes for future improvements:

- Make a DontScroll variable for each side of a platform so otter doesnt get stuck when sliding off
- add bunny and bee enemies
- restrict foliage location from gaps
- fix bug were starting forground position is off when otter returns to the start position
- redefine collision class to have only 4 variables defining the hitbox and not 8 (remove duplicate values)
- implement a menue class and transfer the game scrren operations to that class
- fix foliage deconstructor
- optimise all float vales (make sure they are float and not double)
*/