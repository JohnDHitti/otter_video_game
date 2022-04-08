#include "Polling.h"

Polling::Polling()
{
}
// Sets bool variables to true based on what keys are pressed
void Polling::pollingUpdate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		right = true;
		lastPoll = true;
	}
	else {
		right = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		left = true;
		lastPoll = false;
	}
	else {
		left = false;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		up = true;
	}
	else {
		up = false;
	}

}
