#include "Bee.h"

void Bee::initBee()
{
	//Load Textures
	this->beeTexture1.loadFromFile("beebuzz1.png");
	this->beeTexture2.loadFromFile("beebuzz2.png");
	this->beeTexture3.loadFromFile("beebuzz3.png");
	this->beeStingTexture1.loadFromFile("beesting1.png");
	this->beeStingTexture2.loadFromFile("beesting2.png");
	this->beeStingTexture3.loadFromFile("beesting3.png");
	this->bee.setTexture(beeTexture1);
	bee.scale(0.5f, 0.5f);
}

void Bee::updateBee()
{
	if (beeAnimationClock.getElapsedTime().asSeconds() > 0.05f) {

		if (bee.getTexture() == &beeTexture1)
			bee.setTexture(beeTexture2);
		else if (bee.getTexture() == &beeTexture2)
			bee.setTexture(beeTexture3);
		else
			bee.setTexture(beeTexture1);
		beeAnimationClock.restart();
	}
}

void Bee::renderBee(sf::RenderWindow* window)
{
	window->draw(this->bee);
}

Bee::Bee()
{
	this->initBee();
	this->beePhysics.setInit(700.f, 450.f);
	this->bee.setPosition(beePhysics.pX, beePhysics.pY);
}

Bee::Bee(float a, float b)
{
	this->initBee();
	this->beePhysics.setInit(a, b);
	this->bee.setPosition(beePhysics.pX, beePhysics.pY);
}
