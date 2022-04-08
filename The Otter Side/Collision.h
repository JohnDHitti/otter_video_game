#pragma once

struct Vector {
	float x = 0;
	float y = 0;
};
struct Hitbox {
	//structure for a hitbox that resembles a rectangle
	Vector topLeft;
	Vector topRight;
	Vector bottomLeft;
	Vector bottomRight;
};
class Collision
{
private:
	// Length of the hitbox
	float xLength = 0;
	float yLength = 0;

public:
	Hitbox hitbox;
	Collision();
	//These functions work by sending true of the original hitbox is colliding with the "bullet" hitbox which is sent via parameter
	bool collideFromLeft(Hitbox bullet);
	bool collideFromRight(Hitbox bullet);
	bool collideFromBottom(Hitbox bullet);
	bool collideFromTop(Hitbox bullet);
	void setHitbox(float x, float y);
	void updateHitbox(float x, float y);
};
 