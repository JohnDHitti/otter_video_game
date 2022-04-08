#include "Collision.h"

Collision::Collision()
{
}

bool Collision::collideFromLeft(Hitbox bullet)
{
	//makes sure bullet is in the y path of obj
	if (bullet.bottomRight.y>hitbox.topLeft.y+40&&bullet.topRight.y<hitbox.bottomLeft.y-10) {
		// make sure not true for values past hitbox (plus 1 so not to interefere with other collision functions)
		if (bullet.bottomLeft.x < hitbox.topRight.x-40) {
			//check if x val overlap on desired side
			if (bullet.bottomRight.x > hitbox.topLeft.x) {
				return true;
			}
		}
	}
	return false;
}

bool Collision::collideFromRight(Hitbox bullet)
{
	//makes sure bullet is in the y path of obj
	if (bullet.bottomLeft.y>hitbox.topRight.y+40&&bullet.topLeft.y<hitbox.bottomRight.y-10) {
		// make sure not true for values past hitbox 
		if (bullet.bottomRight.x > hitbox.topLeft.x+40) {
			//check if x val overlap
			if (bullet.bottomLeft.x < hitbox.topRight.x) {
				return true;
			}
}
	}
	return false;
}

bool Collision::collideFromBottom(Hitbox bullet)
{
	//makes sure bullet is in the y path of obj
	if (bullet.topRight.x>hitbox.bottomLeft.x+40&&bullet.topLeft.x<hitbox.bottomRight.x-40) {
		// make sure not true for values past hitbox
		if (bullet.bottomLeft.y > hitbox.topLeft.y + 60) {
			//check if x val overlap
			if (bullet.topLeft.y < hitbox.bottomLeft.y) {
				return true;
			} 
		}
	}
	return false;
}

bool Collision::collideFromTop(Hitbox bullet)
{
	//makes sure bullet is in the y path of obj
	if (bullet.bottomRight.x > hitbox.topLeft.x+40 && bullet.bottomLeft.x < hitbox.topRight.x-40) {
		// make sure not true for values past hitbox
		if (bullet.topLeft.y < hitbox.bottomLeft.y - 60) {
			//check if x val overlap
			if (bullet.bottomLeft.y > hitbox.topLeft.y) {
				return true;
			}
		} 
	}
	return false;
}

void Collision::setHitbox(float x, float y)
{
	// sets the size of the hitbox
	xLength = x;
	yLength = y;
}

void Collision::updateHitbox(float x, float y)
{
	//sets the position of the hitbox (after the length has been defined)
	hitbox.topLeft.x = x;
	hitbox.topLeft.y = y;

	hitbox.bottomLeft.x = x;
	hitbox.bottomLeft.y = y + yLength;

	hitbox.topRight.x = x + xLength;
	hitbox.topRight.y = y;

	hitbox.bottomRight.x = x + xLength;
	hitbox.bottomRight.y = y + yLength;
}
