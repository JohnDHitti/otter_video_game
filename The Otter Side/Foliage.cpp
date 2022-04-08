#include "Foliage.h"

int Foliage::generateRandom(float min, float max)
{
	// Generates a random integer with a min value and a max value
	return min + (rand() % static_cast<int>(max - min + 1));
}

Foliage::Foliage()
{
}


void Foliage::initFoliage(float chunkStart,float chunkEnd, float chunkScaleFactor)
{
	// Initalizes the foliage for the chunk
	//Load textures
	this->grass1Texture.loadFromFile("gress1.png");
	this->grass2Texture.loadFromFile("gress2.png");
	this->treeTexture.loadFromFile("tree.png");
	// Initalize random amount of items
	amountOfGrass1 = generateRandom(1, 5);
	amountOfGrass2 = generateRandom(1, 5);
	amountOfTrees = generateRandom(1, 2);
	grass1 = new sf::Sprite[amountOfGrass1];
	grass2 = new sf::Sprite[amountOfGrass2];
	tree = new sf::Sprite[amountOfTrees];
	// set textures
	for (int i = 0; i < amountOfGrass1; i++) {
		grass1[i].setTexture(grass1Texture);
	}
	for (int i = 0; i < amountOfGrass2; i++) {
		grass2[i].setTexture(grass2Texture);
	}
	for (int i = 0; i < amountOfTrees; i++) {
		tree[i].setTexture(treeTexture);
	}
	// set random scale for each
	for (int i = 0; i < amountOfGrass1; i++) {
		grass1[i].setScale(chunkScaleFactor* generateRandom(100, 110) / 100, chunkScaleFactor* generateRandom(100, 110) / 100);
	}
	for (int i = 0; i < amountOfGrass2; i++) {
		grass2[i].setScale(chunkScaleFactor * generateRandom(100, 110) / 100, chunkScaleFactor * generateRandom(100, 110) / 100);
	}
	for (int i = 0; i < amountOfTrees; i++) {
		tree[i].setScale(chunkScaleFactor * generateRandom(100, 110) / 100, chunkScaleFactor * generateRandom(100, 110) / 100);
	}
	// set random positions
	for (int i = 0; i < amountOfGrass1; i++) {
		grass1[i].setPosition(generateRandom(chunkStart,chunkEnd), 0);
	}
	for (int i = 0; i < amountOfGrass2; i++) {
		grass2[i].setPosition(generateRandom(chunkStart, chunkEnd), 0);
	}
	for (int i = 0; i < amountOfTrees; i++) {
		tree[i].setPosition(generateRandom(chunkStart, chunkEnd), 50);
	}
}

void Foliage::updateFoliage(bool left, bool right, float otterSpeed)
{
	// Updates each piece of foliage
	if (right) {
		for (int i = 0; i < amountOfGrass1; i++) {
			grass1[i].move(-otterSpeed, 0);
		}
		for (int i = 0; i < amountOfGrass2; i++) {
			grass2[i].move(-otterSpeed, 0);
		}
		for (int i = 0; i < amountOfTrees; i++) {
			tree[i].move(-otterSpeed, 0);
		}
	}
	if (left) {
		for (int i = 0; i < amountOfGrass1; i++) {
			grass1[i].move(otterSpeed, 0);
		}
		for (int i = 0; i < amountOfGrass2; i++) {
			grass2[i].move(otterSpeed, 0);
		}
		for (int i = 0; i < amountOfTrees; i++) {
			tree[i].move(otterSpeed, 0);
		}
	}
}

void Foliage::renderFoliage(sf::RenderWindow* window)
{
	// renders each piece of grass
	for (int i = 0; i < amountOfGrass1; i++) {
		window->draw(this->grass1[i]);
	}
	for (int i = 0; i < amountOfGrass2; i++) {
		window->draw(this->grass2[i]);
	}
}

void Foliage::renderTrees(sf::RenderWindow* window)
{
	// renders trees
	for (int i = 0; i < amountOfTrees; i++) {
		window->draw(this->tree[i]);
	}

}
// deconstructor
Foliage::~Foliage()
{
		delete[]  grass1;
		delete[] grass2;
		delete[] tree;
}
