#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Platform
{
private:
	//platform sprites
	sf::Sprite left;
	sf::Sprite right;
	sf::Sprite* mid;
	//platform taxtures
	sf::Texture leftTexture;
	sf::Texture midTexture;
	sf::Texture rightTexture;
	// Variables/Constants
	float blockXDeminsion = 214;
	float blockYDeminsion = 217;
	float scaleFactor = 0.83;
	int midSize = 0;
	float initX = 0;
	float initY = 0;
public:
	Platform();
	void initPlatform(float x, float y, int l);
	void updatePlatform(float otterSpeed, bool right, bool left);
	void renderPlatform(sf::RenderWindow* window);
	//return deminsions
	float returnTopLeftX();
	float returnBottomLeftX();
	float returnBottomRightX();
	float returnTopRightX();
	float returnTopLeftY();
	float returnBottomLeftY();
	float returnBottomRightY();
	float returnTopRightY();
	float returnBlockXDemension();
	float returnBlockYDemension();
	float returnScaleFactor();
	int returnMidSize();
	~Platform();
};

