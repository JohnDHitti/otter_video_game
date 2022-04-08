#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Physics.h"
#include "Polling.h"
class Bee
{
private:
	// Constants

	// Otter Textures/Sprite
	sf::Sprite bee;
	sf::Texture beeTexture1;
	sf::Texture beeTexture2;
	sf::Texture beeTexture3;
	sf::Texture beeStingTexture1;
	sf::Texture beeStingTexture2;
	sf::Texture beeStingTexture3;

	sf::Clock beeAnimationClock;
	void initBee();

public:
	Physics beePhysics;
	void updateBee();
	void renderBee(sf::RenderWindow* window);
	// Constructors/Destructors
	Bee();
	Bee(float a, float b);
};