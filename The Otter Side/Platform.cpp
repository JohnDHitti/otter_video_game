#include "Platform.h"

Platform::Platform()
{

}

void Platform::initPlatform(float x, float y, int l)
{
	// This initalizes the platforms
	midSize = l;
	initX = x;
	initY = y;
	//load in textures
	this->leftTexture.loadFromFile("startblock.png");
	this->rightTexture.loadFromFile("endblock.png");
	this->midTexture.loadFromFile("block.png");
	// declare array of sprites of size l
	mid = new sf::Sprite[midSize];
	// set textures
	left.setTexture(leftTexture);
	right.setTexture(rightTexture);
	for (int i = 0; i < midSize; i++) {
		mid[i].setTexture(midTexture);
	}
	left.setPosition(x, y);
	for (int i = 0; i < midSize; i++) {
		mid[i].setPosition(x+i*blockXDeminsion*scaleFactor,y);
	}
	right.setPosition(x + (midSize) * blockXDeminsion* scaleFactor, y);
	// set scale factor
	left.scale(scaleFactor, scaleFactor);
	for (int i = 0; i < midSize; i++) {
		mid[i].scale(scaleFactor, scaleFactor);
	}
	right.scale(scaleFactor, scaleFactor);
}


void Platform::updatePlatform(float otterSpeed, bool right, bool left)
{
// Update function for platforms
	if (right) {
		this->left.move(-otterSpeed, 0);
		for (int i = 0; i < midSize; i++) {
			this->mid[i].move(-otterSpeed, 0);
		}
		this->right.move(-otterSpeed, 0);
	}
	if (left) {
		this->left.move(otterSpeed, 0);
		for (int i = 0; i < midSize; i++) {
			this->mid[i].move(otterSpeed, 0);
		}
		this->right.move(otterSpeed, 0);
	}
}

void Platform::renderPlatform(sf::RenderWindow* window)
{
	// render function for platforms
	window->draw(this->left);
	for (int i = 0; i < midSize; i++) {
		window->draw(this->mid[i]);
	}
	window->draw(this->right);
}


// return functions
float Platform::returnTopLeftX()
{
	return initX;
}

float Platform::returnBottomLeftX()
{
	return initX;
}

float Platform::returnBottomRightX()
{
	return initX+blockXDeminsion*scaleFactor*(2+midSize);
}

float Platform::returnTopRightX()
{
	return initX + blockXDeminsion * scaleFactor * (2 + midSize);
}

float Platform::returnTopLeftY()
{
	return initY;
}

float Platform::returnBottomLeftY()
{
	return initY + blockYDeminsion * scaleFactor;
}

float Platform::returnBottomRightY()
{
	return initY + blockYDeminsion*scaleFactor;
}

float Platform::returnTopRightY()
{
	return initY;
}

float Platform::returnBlockXDemension()
{
	return blockXDeminsion;
}

float Platform::returnBlockYDemension()
{
	return blockYDeminsion;
}

float Platform::returnScaleFactor()
{
	return scaleFactor;
}

int Platform::returnMidSize()
{
	return midSize;
}


// deconstructor
Platform::~Platform()
{
	delete[] mid;
}
