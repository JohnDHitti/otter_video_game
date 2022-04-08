#include "Level1.h"
#include "Physics.h"

void Level1::initLevel1()
{
	//INIT BACKGROUND
	// Loading Textures
	this->bgTexture.loadFromFile("bg1.png");
	// Set Init Texture
	bg.setTexture(bgTexture);
	// Set Scale Factors
	bg.scale(scaleFactor,scaleFactor);
	// initalize otter hitbox
	otterCollision.setHitbox((otter.returnOtterXDemension()-otter.returnOtterHeadDemension()*3) * otter.returnScaleFactor(), otter.returnOtterYDemension() * otter.returnScaleFactor());
}	

void Level1::updateEnemies()
{
	// currently not used
}

void Level1::renderEnemies(sf::RenderWindow* window)
{
	// currently not used
}

void Level1::updatebg()
{
	// Updates the background image as the otter moves through the level
	dontScroll = false;
	onBorder = false;
	if (otter.otterPolling.right&&!dontScrollbg&&!dead) {
		bgPhysics.pX = bgPhysics.pX - backgroundSpeed;
		this->bg.setPosition(bgPhysics.pX, bgPhysics.pY);

	}
	if (otter.otterPolling.left&&!dontScrollbg&&!dead) {

		bgPhysics.pX = bgPhysics.pX + backgroundSpeed;
		this->bg.setPosition(bgPhysics.pX, bgPhysics.pY);
	}
	// make sure background doesnt scroll too far
	if (-bgPhysics.pX < 0) {
		dontScroll = true;
		bgPhysics.pX = 0;
		onBorder = true;
	}
}

/*
The game is designed so that the level can be designed in one function. This also allows for an easier conversion to a game where the otter would run forever (procedurally generated terrain)
This level contains 5 chunks (this can be ajusted in level1.h)
each chunk must be initalized as such
chunks[number of the chunk].initChunk(first platform type, second platform type, third platform type, gap distance, previous chunk length)
the platform types are as follows
0=normal platform
1= left side of gap
2=right side of gap
3=final water platfrom

sky platforms must then be generated. Call the function chunks[x].setPlatformAmount(the amount of sky platforms you want);
then they must be initalized as such. chunks[x].initPlatform(platform number (starting at 0), x-location, y-location, sky platform length(how many segments in the desired platfrom));
*/


void Level1::initAllChunks()
{
    // ------- INITALIZEZ THE DATA FOR LEVEL 1 ------- (note above on how this works)
	chunks[0].initChunk(0, 1, 2, 500.f, 0);
	chunks[1].initChunk(1, 2, 0, 800.f, chunks[0].returnChunkXLength());
	chunks[1].setPlatformAmount(3);
	chunks[1].initPlatform(0, 6500, 600, 1);
	chunks[1].initPlatform(1, 7500, 300, 3);
	chunks[1].initPlatform(2, 10000, 600, 7);
	chunks[2].initChunk(1, 2, 0, 2000.f, chunks[1].returnChunkXLength());
	chunks[2].setPlatformAmount(2);
	chunks[2].initPlatform(0, 15300, 300, 7);
	chunks[2].initPlatform(1, 14500, 600, 0);
	chunks[3].initChunk(1, 2, 0, 800.f, chunks[2].returnChunkXLength());
	chunks[3].setPlatformAmount(4);
	chunks[3].initPlatform(0, 21215, 600, 6);

	chunks[3].initPlatform(1, 25000, 600, 3);
	chunks[3].initPlatform(2, 26600, 300, 7);
	chunks[3].initPlatform(3, 29000, 300, 0);
	chunks[4].initChunk(1, 2, 3, 600.f, chunks[3].returnChunkXLength());
	

	//records lengths of chunks into an array
	for (int i = 0; i < chunkAmount; i++) {
		chunkLengths[i] = chunks[i].returnChunkXLength();
	}
	// segments the lengths into 6 parts
	for (int i = 1; i < chunkAmount+1; i++) {
		chunkLengthsPlus[i] = chunkLengths[i-1];
	}
	// record total amount of platforms
	for (int i = 0; i < chunkAmount; i++) {
		totalAmountOfPlatforms += chunks[i].returnPlatfromCounter();
	}
	// Initalizs the hitboxes for platforms
	platformCollision = new Collision[totalAmountOfPlatforms];
	// goes through each platform and sets the deminsions of the hit box
	platformCollisionCounter = 0;
	for (int i = 0; i < chunkAmount; i++) {
		for (int j = 0; j < chunks[i].returnPlatfromCounter(); j++) {
			platformCollision[platformCollisionCounter].setHitbox(chunks[i].returnPlatformXDemension(j),chunks[i].returnPlatformYDemension(j));
			platformCollision[platformCollisionCounter].updateHitbox(chunks[i].returnPlatformXPosition(j), chunks[i].returnPlatformYPosition(j)+10);//+10 to move hitbox offcenter so otter is on platform
			platformCollisionCounter += 1;
		}
		
	}
}

void Level1::updateChunks()
{
	// Updates each chunk
	for (int i = 0; i < chunkAmount; i++) {
		chunks[i].updateChunk(otter.otterPolling.left, otter.otterPolling.right, otter.otterSpeedReturn(),dontScroll);
	}
}

void Level1::renderChunks(sf::RenderWindow* window)
{
	// Renders chunks according to if the otter is in the chunk
	if (-chunks[0].returnChunkXPos()-chunks[0].returnStartOffset() > chunkLengthsPlus[chunkRenderPosition - 1] * chunks[0].returnScaleFactor() && -chunks[0].returnChunkXPos()-chunks[0].returnStartOffset() < chunkLengthsPlus[chunkRenderPosition + 2] * chunks[0].returnScaleFactor()) {

		chunks[chunkRenderPosition].renderChunk(window);
		chunks[chunkRenderPosition-1].renderChunk(window);
		chunks[chunkRenderPosition+1].renderChunk(window);
	}
	if (-chunks[0].returnChunkXPos() - chunks[0].returnStartOffset()> chunkLengthsPlus[chunkRenderPosition +1] * chunks[0].returnScaleFactor()) {
		chunkRenderPosition += 1;
	}
	if (-chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() < chunkLengthsPlus[chunkRenderPosition] * chunks[0].returnScaleFactor()) {
		chunkRenderPosition -= 1;
	}
	if (chunkRenderPosition == 0)
		chunkRenderPosition = 1;
	if (chunkRenderPosition == chunkAmount-1)
		chunkRenderPosition = chunkAmount-2;

}

void Level1::renderChunksFoliage(sf::RenderWindow* window)
{
	// Renders chunk foliage according to if the otter is in the chunk
	if (-chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() > chunkLengthsPlus[chunkRenderPosition - 1] * chunks[0].returnScaleFactor() && -chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() < chunkLengthsPlus[chunkRenderPosition + 2] * chunks[0].returnScaleFactor()) {

		chunks[chunkRenderPosition].renderChunkFoliage(window);
		chunks[chunkRenderPosition - 1].renderChunkFoliage(window);
		chunks[chunkRenderPosition + 1].renderChunkFoliage(window);
	}


}

void Level1::renderChunksTree(sf::RenderWindow* window)
{
	// Renders chunk trees according to if the otter is in the chunk (these are seperate so the trees can be renderd before the otter and other foreground items)
	if (-chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() > chunkLengthsPlus[chunkRenderPosition - 1] * chunks[0].returnScaleFactor() && -chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() < chunkLengthsPlus[chunkRenderPosition + 2] * chunks[0].returnScaleFactor()) {

		chunks[chunkRenderPosition].renderChunkTree(window);
		chunks[chunkRenderPosition - 1].renderChunkTree(window);
		chunks[chunkRenderPosition + 1].renderChunkTree(window);
	}


}

void Level1::deathCheck()
{
	// checks if the otter has fallen into a gap and sets the game into game over mode
	for (int i = 0; i < chunkAmount; i++) {
		if (chunks[i].death()) {
			if (otter.otterDeath()) {
				dead = true;
			}
		}
	}
	//display game over screen
	if (otter.otterPhysics.pY > 2000) {
		gameOver = true;
	}
}

void Level1::levelCompleteCheck()
{
	// checks to see if the level is complete and sets the game to game complete mode
	if (-chunks[0].returnChunkXPos() - chunks[0].returnStartOffset() > (chunks[chunkAmount - 1].returnChunkXLength() - 1600)*chunks[0].returnScaleFactor()) {
		levelComplete = true;
	}
}

void Level1::updateCollisions()
{
	// this function is responsable for updating all the collisions the otter may have with the platfroms and excicutes a command based on what side the otter hit

	otterCollision.updateHitbox(-chunks[0].returnChunkXPos()-chunks[0].returnStartOffset()+(otter.returnOtterHeadDemension()*otter.returnScaleFactor()), otter.otterPhysics.pY);
	if (!onBorder) {
		dontScroll = false;
	}
	dontScrollbg = false;
	otter.otterPhysics.initPosY = otter.otterPhysics.initPosYsave;
	for (int i = 0; i < totalAmountOfPlatforms; i++) {
		// hit from resets otter velocity
		if (platformCollision[i].collideFromBottom(otterCollision.hitbox)) {
			if (otter.otterPhysics.pY < platformCollision[i].hitbox.bottomLeft.y) {
				otter.otterPhysics.vY = 0;
				otter.otterPhysics.pY = platformCollision[i].hitbox.bottomLeft.y;
			}
		}
		// hit from top sets otter a new ground position
		if (platformCollision[i].collideFromTop(otterCollision.hitbox)) {
			otter.otterPhysics.initPosY = platformCollision[i].hitbox.topLeft.y-otter.returnOtterYDemension()*otter.returnScaleFactor()+1;
		}
		//hit from and right stop movements in the x position
		if (platformCollision[i].collideFromLeft(otterCollision.hitbox)) {
			dontScroll = true;
			dontScrollbg = true;
		}
		if (platformCollision[i].collideFromRight(otterCollision.hitbox)) {
			dontScroll = true;
			dontScrollbg = true;
		}
	}
	
}

// CONSTRUCTOR
Level1::Level1()
{
	this->initAllChunks();
	this->initLevel1();
}

// UPDATE LEVEL
void Level1::updateLevel()
{
	this->updatebg();
	if (!dead) {
		this->updateCollisions();
		this->updateChunks();
	}
	otter.updateOtter();
	this->deathCheck();
	this->levelCompleteCheck();
	this->updateEnemies();
}
// RENDER LEVEL
void Level1::renderLevel(sf::RenderWindow* window)
{
	window->draw(this->bg);
	this->renderChunksTree(window);
	this->renderChunks(window);
	otter.renderOtter(window);
	this->renderChunksFoliage(window);
	this->renderEnemies(window);
}

bool Level1::returnGameOver()
{
	return gameOver;
}

bool Level1::returnLevelComplete()
{
	return levelComplete;
}

Level1::~Level1()
{
	delete[] platformCollision;
}


