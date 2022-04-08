#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Otter.h"
#include "Bee.h"
#include "Chunk.h"
#include "Collision.h"
class Level1
{
private:
	void initLevel1();
	// Charcter
	Otter otter;
	// Enemies (Currently not used)
	int beeEnemyAmount = 3;
	Bee bee[3];
	void updateEnemies();
	void renderEnemies(sf::RenderWindow* window);
	// Background
	sf::Sprite bg;
	sf::Texture bgTexture;
	Physics bgPhysics;
	float backgroundSpeed = 0.5;
	float scaleFactor = 0.83f;
	void updatebg();
	// Foreground
	Chunk chunks[5];
	int chunkAmount = 5;// amount of chunks in the game
	int chunkLengths[5];// records the length of the chunks
	int chunkLengthsPlus[6] = {0,0,0,0,0,0};// records the lengths of the chunks with a starting variable of 0
	int chunkRenderPosition = 1;//tells were the otter is and which chunks to render
	// bool variable controlling scrolling (used to determine if screen should move)
	bool dontScroll;
	bool dontScrollbg = false;
	bool onBorder = false;
	bool dead = false;
	bool gameOver = false;
	bool levelComplete = false;
	// ------
	int totalAmountOfPlatforms = 0;
	void initAllChunks();
	void updateChunks();
	void renderChunks(sf::RenderWindow* window);
	void renderChunksFoliage(sf::RenderWindow* window);
	void renderChunksTree(sf::RenderWindow* window);
	void deathCheck();
	void levelCompleteCheck();
	// Collision
	Collision otterCollision;
	Collision* platformCollision; // Initalized as array of collision for the amount of platforms
	int platformCollisionCounter = 0; // used to count through platform collision arrays
	void updateCollisions();
public:
	// Constructors/Destructors
	Level1();
	void updateLevel();
	void renderLevel(sf::RenderWindow* window);
	bool returnGameOver();
	bool returnLevelComplete();
	~Level1();
};