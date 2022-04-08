#include "Physics.h"
void Physics::setInit(float a, float b)
{
	this->initPosX = a;
	this->initPosY = b;
	this->initPosYsave = b;
	this->pX = initPosX;
	this->pY = initPosY;
}
// CONSTRUCTOR
Physics::Physics()
{
}

void Physics::updatePhysLeft()
{
	// currently unused
}

void Physics::updatePhysRight()
{
	// currently unused
}
 
void Physics::updatePhysJump()
{
	// currently unused
}

void Physics::physUpdate()
{
	//Updates the position based on velocity and velocity based on acceleration
	vX += aX;
	vY += aY;
	pX += vX;
	pY += vY;
}

void Physics::applyGravity()
{
	// applys gravity if the otter is not at the inital y position (which can change if hes on a platform or in a gap)
	if (pY < initPosY)
		vY += gravity;
	else if (pY > initPosY)
		pY = initPosY;
}

