#include "Game.h"
// Private Functions
void Game::initVar()
{
	// Initalizes the window pointer
	this->window = nullptr;

}
void Game::initWindow()
{
	// Defines the video mode and demensions of the window as well as the frame limit
	// Note: frame limit determins the amount of updates per second
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "DEMO V0.1"/*, sf::Style::Titlebar | sf::Style::Close |sf::Style::Fullscreen*/);
	this->window->setFramerateLimit(60);
}


void Game::startScreen()
{
	// This function starts the game if space is pressed on the start screen
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		start = true;
	}
	updateGameStartScreen();
}

void Game::initScreens()
{
	// This function loads all the textures of the start screens and loads the textures to their specific sprites
	this->gameOverScreenTexture.loadFromFile("GAMEOVER.png");
	this->gameCompletionScreenTexture.loadFromFile("ENDSCREEN.png");
	this->gameStartScreenTexture.loadFromFile("STARTSCREEN.png");
	this->gameStartScreenTexturebg.loadFromFile("STARTSCREENBG.png");
	this->gameCompletionScreen.setTexture(gameCompletionScreenTexture);
	this->gameStartScreen.setTexture(gameStartScreenTexture);
	this->gameStartScreenbg.setTexture(gameStartScreenTexturebg);
	this->gameOverScreen.setTexture(gameOverScreenTexture);
	this->gameOverScreen.setScale(0.5f, 0.5f);
}

void Game::updateGameOverScreen()
{
	// sets game over bool to true
	gameOver = true;
}

void Game::updateGameCompletionScreen()
{
	// sets game completion bool to true
	gameComplete = true;
}

void Game::updateGameStartScreen()
{
	// updates the games starting screen
	this->gameStartScreenbg.setPosition(-screenAnimationClock.getElapsedTime().asMicroseconds()/10000, 0);
	if (screenAnimationClock.getElapsedTime().asMicroseconds() / 10000 == 1900) {
		screenAnimationClock.restart();
	}
}

void Game::renderGameOverScreen()
{
	// renders the game over screen
	window->draw(gameOverScreen);

}

void Game::renderGameCompletionScreen()
{
	// renders the game completion screen
	window->draw(gameCompletionScreen);
}

void Game::renderGameStartScreen()
{
	// renders the game start screen
	window->draw(gameStartScreenbg);
	window->draw(gameStartScreen);
}

// Constructor/Deconstructor
Game::Game()
{
	// initalizes the variables,window,and game screens
	this->initVar();
	this->initWindow();
	this->initScreens();
}
Game::~Game()
{
	// deletes the window and all of its data
	delete this->window;
}


const bool Game::getWindowIsOpen() const
{
	// returns true if the game window is open
	return this->window->isOpen();
}

void Game::pollEvents()
{
	// Closes the window if escape or x button is pressed
	while (this->window->pollEvent(this->event))
	{
		//Exit Game
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	/*Updates mouse position relative to window*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
/*
Notes on update and render functions:

Most classes have an update and a render function that is called to update items in a class then render them. These are all called here but often contain more functions called within fuctions (creating a tree looking type of function call).
Some update and render functions also contain calls to other functions in the class that help to relocate clutterd code but do not call another classes updare and render functions.
*/
void Game::update()
{
	//Updates game object
	this->pollEvents();
	// Updates mouse position (currently not used in game) 
	this->updateMousePositions();
	// This set of if statments runs the game according to what state the main character is in (start screen, playing the game, game over screen, ect.)
	if (!start) {
		this->startScreen();
	}
	if (!Level1.returnGameOver()&&start&&!Level1.returnLevelComplete()) {
		Level1.updateLevel();
	}
	if(Level1.returnGameOver()) {
		this->updateGameOverScreen();
	}
	if (Level1.returnLevelComplete()) {
		updateGameCompletionScreen();
	}

}

void Game::render()
{
	//clears previous window
	this->window->clear();
	//renders game objects
	if (!start) {
		renderGameStartScreen();
	}else{
		Level1.renderLevel(this->window);
		if (gameOver) {
			this->renderGameOverScreen();
		}
		if (gameComplete) {
			this->renderGameCompletionScreen();
		}
	}
	//displays objects
	this->window->display();
}