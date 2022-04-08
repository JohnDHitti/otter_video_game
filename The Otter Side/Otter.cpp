#include "Otter.h"
#include <iostream>

void Otter::initOtter()
{
	//Load Textures
	this->otterTexture1.loadFromFile("ottera.png");
	this->otterTexture2.loadFromFile("otterb.png");
	this->otterTexture3.loadFromFile("otterc.png");
	this->otterTexture1rev.loadFromFile("otterarev.png");
	this->otterTexture2rev.loadFromFile("otterbrev.png");
	this->otterTexture3rev.loadFromFile("ottercrev.png");
	// set texture,scale texture, set inital position
	this->otter.setTexture(otterTexture1);
	otter.scale(scalefactor, scalefactor);
	this->otterPhysics.setInit(700.f, 800.f);
	this->otter.setPosition(otterPhysics.pX,otterPhysics.pY);
}
void Otter::moveLeft()
{
	// WALK CYCLE Left
	if (otterPolling.left) {
		//Animation Cycle
		if (otterAnimationClock.getElapsedTime().asSeconds() > 0.1f && !otterPolling.up) {

			if (otter.getTexture() == &otterTexture1rev)
				otter.setTexture(otterTexture2rev);
			else if (otter.getTexture() == &otterTexture2rev)
				otter.setTexture(otterTexture3rev);
			else
				otter.setTexture(otterTexture1rev);
			otterAnimationClock.restart();
		}
	}
}
void Otter::moveRight()
{
	// WALK CYCLE RIGHT
	if (otterPolling.right) {
		//Animation Cycle
		if (otterAnimationClock.getElapsedTime().asSeconds() > 0.1f && !otterPolling.up) {

			if (otter.getTexture() == &otterTexture1)
				otter.setTexture(otterTexture2);
			else if (otter.getTexture() == &otterTexture2)
				otter.setTexture(otterTexture3);
			else
				otter.setTexture(otterTexture1);

			otterAnimationClock.restart();
		}
	}
}
void Otter::moveJump()
{	
	// JUMP
	if (otterPolling.up) {
		if (otterPhysics.pY == otterPhysics.initPosY) {
			if (otterPolling.right)
				otter.setTexture(otterTexture3);
			if (otterPolling.left)
				otter.setTexture(otterTexture3rev);
			otterPhysics.vY = otterJumpForce;
		}
	}
}
Otter::Otter()
{
	this->initOtter();
}

void Otter::updateOtter()
{
	// UPDATE KEYSTROKES
	otterPolling.pollingUpdate();
	//Move
	this->moveJump();
	this->moveLeft();
	this->moveRight();

	//Set Animation to default if not running
	if (!otterPolling.left && !otterPolling.right&&!otterPolling.up) {
		if (otterPolling.lastPoll) {
			otter.setTexture(otterTexture1);
		}
		else {
			otter.setTexture(otterTexture1rev);
		}

	}
	otterPhysics.physUpdate();
	
	// Applies Gravity 
	
		
	otterPhysics.applyGravity();


	// Updates Position
	this->otter.setPosition(otterPhysics.pX, otterPhysics.pY);
}

void Otter::renderOtter(sf::RenderWindow* window)
{
	window->draw(this->otter);
}

float Otter::otterSpeedReturn()
{
	return otterSpeed;
}

bool Otter::otterDeath()
{
	// if the otter falls in a gab its y position limit will be set high so it appears to fall 
	if (otterPhysics.pY == 800.f) {
		otterPhysics.initPosY = 10000;
		otterPhysics.initPosYsave = 10000;
		return true;
	}
	return false;
}

float Otter::returnOtterXDemension()
{
	return otterXDemension;
}

float Otter::returnOtterYDemension()
{
	return otterYDemension;
}

float Otter::returnOtterHeadDemension()
{
	return otterHeadDemension;
}

float Otter::returnScaleFactor()
{
	return scalefactor;
}
