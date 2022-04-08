#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Physics.h"
#include "Polling.h"
class Otter
{
private:
	// Constants
	float otterJumpForce = -45.f;
	float otterSpeed = 25.f;
	float scalefactor = 0.3f;
	float otterXDemension = 1336;
	float otterYDemension = 876;
	float otterHeadDemension = 300;
	// Otter Textures/Sprite
	sf::Sprite otter;
	sf::Texture otterTexture1;
	sf::Texture otterTexture2;
	sf::Texture otterTexture3;
	sf::Texture otterTexture1rev;
	sf::Texture otterTexture2rev;
	sf::Texture otterTexture3rev;
	sf::Clock otterAnimationClock; // clock for controlling animation
	void initOtter();
	void moveLeft();
	void moveRight();
	void moveJump();
public:
	Polling otterPolling; // records keyboard movements
	Physics otterPhysics; // holds position data for otter
	void updateOtter();
	void renderOtter(sf::RenderWindow* window);
	float otterSpeedReturn();
	bool otterDeath();
	float returnOtterXDemension();
	float returnOtterYDemension();
	float returnOtterHeadDemension();
	float returnScaleFactor();
	// Constructors/Destructors
	Otter();
};

