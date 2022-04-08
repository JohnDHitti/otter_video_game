#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bee.h"
#include "Rabbit.h"
#include <stdlib.h>
class Foliage
{
private:
	// Sprites/Objects
	sf::Sprite* grass1;
	sf::Sprite* grass2;
	sf::Sprite* tree;
	// Textures
	sf::Texture treeTexture;
	sf::Texture grass1Texture;
	sf::Texture grass2Texture;
	// Random Generators
	int generateRandom(float min, float max);
	// variables
	int amountOfGrass1 = 0;
	int amountOfGrass2 = 0;
	int amountOfTrees = 0;
public:
	Foliage();
	void initFoliage(float chunkStart, float chunkEnd, float chunkScaleFactor);
	void updateFoliage(bool left, bool right, float otterSpeed);
	void renderFoliage(sf::RenderWindow* window);
	void renderTrees(sf::RenderWindow* window);
	~Foliage();
};

