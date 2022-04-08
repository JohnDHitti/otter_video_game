#include "Chunk.h"


void Chunk::initChunk(int a, int b, int c, float d, float e)
{
	// Loading Textures
	this->platformDropATexture.loadFromFile("platformsplita.png");
	this->platformDropBTexture.loadFromFile("platformsplitb.png");
	this->mainPlatformTexture.loadFromFile("mainplat1.png");
	this->platformWaterTexture.loadFromFile("platformwater.png");
	// Set Init Texture and positions
	chunkXLength += e;
	previousChunkLength += e;
	gapLength = d;
		//This sets the proper texture for the first ground platfrom based on the sent parameters
	this->fg1.setPosition(fgPhysics.pX + (chunkXLength * scaleFactor), fgPhysics.pY);
	{
		if (a == 0) {
			fg1.setTexture(mainPlatformTexture); 
			chunkXLength += 3840.f;
			section1Length += 3840.f;
		}
		if (a == 1) {
			fg1.setTexture(platformDropATexture);
			chunkXLength += (1814.f + d);
			section1Length += (1814.f);
			gapLocation = 1;
		}
		if (a == 2) {
			fg1.setTexture(platformDropBTexture);
			chunkXLength += 2046.f;
			section1Length += 2046.f;
		}
		if (a == 3) {
			fg1.setTexture(platformWaterTexture);
			chunkXLength += 3840.f;
			section1Length += 3840.f;
		}
	}
		//setting texture of plat section 2
	this->fg2.setPosition(fgPhysics.pX + (chunkXLength * scaleFactor), fgPhysics.pY);
	{
		if (b == 0) {
			fg2.setTexture(mainPlatformTexture);
			chunkXLength += 3840.f;
			section2Length += 3840.f;
		}
		if (b == 1) {
			fg2.setTexture(platformDropATexture);
			chunkXLength += (1814.f + d);
			section2Length += (1814.f);
			gapLocation = 2;
		}
		if (b == 2) {
			fg2.setTexture(platformDropBTexture);
			chunkXLength += 2046.f;
			section2Length += 2046.f;
		}
		if (b == 3) {
			fg2.setTexture(platformWaterTexture);
			chunkXLength += 3840.f;
			section2Length += 3840.f;
		}
	}
		//setting texture of plat section 3
	this->fg3.setPosition(fgPhysics.pX + (chunkXLength * scaleFactor), fgPhysics.pY);
	{
		if (c == 0) {
			fg3.setTexture(mainPlatformTexture);
			chunkXLength += 3840.f;
			section3Length += 3840.f;
		}
		if (c == 1) {
			fg3.setTexture(platformDropATexture);
			chunkXLength += (1814.f + d);
			section3Length += (1814.f);
		}
		if (c == 2) {
			fg3.setTexture(platformDropBTexture);
			chunkXLength += 2046.f;
			section3Length += 2046.f;
		}
		if (c == 3) {
			fg3.setTexture(platformWaterTexture);
			chunkXLength += 3840.f;
			section3Length += 3840.f;
		}
	}
	// Set Scale Factor
	fg1.scale(scaleFactor, scaleFactor);
	fg2.scale(scaleFactor, scaleFactor);
	fg3.scale(scaleFactor, scaleFactor);
	// Initalize foliage
	foli.initFoliage(previousChunkLength, chunkXLength, scaleFactor);
}

void Chunk::initPlatform(int platformNumber, float x, float y, int l)
{
	//initalizes the platfroms from level1.cpp into the platform class
	platforms[platformNumber].initPlatform(x,y,l);

}



void Chunk::updatePlatforms(bool left, bool right, float otterSpeed)
{
	//updates each platform in a chunk
	for (int i = 0; i < platformCounter; i++) {
		platforms[i].updatePlatform(otterSpeed, right, left);
	}
}

Chunk::Chunk()
{

}

void Chunk::setPlatformAmount(int x)
{
	// sets the amount of platforms needed for a given chunk
	platformCounter = x;
	platforms = new Platform[platformCounter];
}

void Chunk::updateChunk(bool left, bool right, float otterSpeed, bool dontScroll)
{
	//updates forground positions of both terrain segments if otter moves left or right
	for (int i = 0; i < platformCounter; i++) {

	}
	if (!(dontScroll)) {
		this->updatePlatforms(left, right, otterSpeed);
		foli.updateFoliage(left, right, otterSpeed);
		if (right) {
			fgPhysics.pX = fgPhysics.pX - otterSpeed;
			this->fg1.move(-otterSpeed, 0);
			this->fg2.move(-otterSpeed, 0);
			this->fg3.move(-otterSpeed, 0);
		}
		if (left) {
			fgPhysics.pX = fgPhysics.pX + otterSpeed;
			this->fg1.move(otterSpeed, 0);
			this->fg2.move(otterSpeed, 0);
			this->fg3.move(otterSpeed, 0);
		}
	
	}
}

// the four render functions below can be called seperatly as to organize the way in which they are drawn on the screen
void Chunk::renderChunk(sf::RenderWindow* window)
{
	window->draw(this->fg1);
	window->draw(this->fg2);
	window->draw(this->fg3);
	this->renderPlatforms(window);
}

void Chunk::renderChunkFoliage(sf::RenderWindow* window)
{
	foli.renderFoliage(window);
}


void Chunk::renderChunkTree(sf::RenderWindow* window)
{
	foli.renderTrees(window);
}

void Chunk::renderPlatforms(sf::RenderWindow* window)
{
	for (int i = 0; i < platformCounter; i++) {
		platforms[i].renderPlatform(window);
	}

}

// RETURN FUNCTIONS
float Chunk::returnChunkXLength()
{
	return chunkXLength;
}

float Chunk::returnChunkXPos()
{
	return fgPhysics.pX;
}

float Chunk::returnStartOffset()
{
	return startOffset;
}

float Chunk::returnScaleFactor()
{
	return scaleFactor;
}

float Chunk::returnPlatfromCounter()
{
	return platformCounter;
}

float Chunk::returnPlatformXDemension(int platformNumber)
{
	return platforms[platformNumber].returnBlockXDemension()* platforms[platformNumber].returnScaleFactor()*(2+ platforms[platformNumber].returnMidSize());
}

float Chunk::returnPlatformYDemension(int platformNumber)
{
	return platforms[platformNumber].returnBlockYDemension() * platforms[platformNumber].returnScaleFactor();
}

float Chunk::returnPlatformXPosition(int platformNumber)
{
	return platforms[platformNumber].returnTopLeftX();
}

float Chunk::returnPlatformYPosition(int platformNumber)
{
	return platforms[platformNumber].returnTopLeftY();
}

bool Chunk::death()
{
	// returns true if the otter is in a gap (this then triggers the death function in level1.cpp)
	if (gapLocation == 1) {
		if ((previousChunkLength + section1Length) * scaleFactor < (-fgPhysics.pX - startOffset) && (-fgPhysics.pX - startOffset - gapClosure) < (previousChunkLength + section1Length + gapLength) * scaleFactor) {
			return true;
		}
	}
	if (gapLocation == 2) {
		if (((previousChunkLength + section1Length + section2Length) * scaleFactor < (-fgPhysics.pX - startOffset)) && ((-fgPhysics.pX - startOffset - gapClosure) < (previousChunkLength + section1Length + section2Length + gapLength) * scaleFactor)) {
			return true;
		}
	}
	return false;
}

Chunk::~Chunk()
{
	delete[] platforms;
}
