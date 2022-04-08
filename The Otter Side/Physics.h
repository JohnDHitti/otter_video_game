#pragma once
class Physics
{
public:
	// Inital positions
	float initPosX = 0;
	float initPosY = 0;
	// save value of y inital position (for when the inital position is changed when the otter jumps on platforms)
	float initPosYsave = 0;
	// Position
	float pX = initPosX;
	float pY = initPosY;
	// Velocity
	float vX = 0;
	float vY = 0;
	// Acceleration
	float aX = 0;
	float aY = 0;
	// Gravitational Constant
	float gravity = 2;
	Physics();
	void setInit(float a,float b);
	void updatePhysLeft();
	void updatePhysRight();
	void updatePhysJump();
	void physUpdate();
	void applyGravity();
};

