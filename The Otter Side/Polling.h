#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Polling
{
private:
	
public:
	bool left=false;
	bool right = false;
	bool up = false;
	bool lastPoll = true; // records the last left or right keystroke to make sure animation is consistant 
	Polling();
	void pollingUpdate();
};

