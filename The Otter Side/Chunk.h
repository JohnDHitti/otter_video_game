#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Otter.h"
#include "Platform.h"
#include "Foliage.h"
class Chunk
{
private:

	// Foreground Sprites
	sf::Sprite fg1;
	sf::Sprite fg2;
	sf::Sprite fg3;
	// Foreground Physics
	Physics fgPhysics;
	//Foreground Textures
	sf::Texture platformDropATexture;
	sf::Texture platformDropBTexture;
	sf::Texture mainPlatformTexture;
	sf::Texture platformWaterTexture;
	//Foreground Terrain Generation Veriables and Constants
	float fg1pos = 0;
	float fg2pos = 1;
	float fg3pos = 2;
	float assetXDeminsion = 3840.f;
	float scaleFactor = 0.83f;
	float gapJumpFactor = 1.4f;
	float gapJumpFactorRev = -1.4f;
	float gapJumpFactor2 = 2.4f;
	float gapJumpFactor2Rev = 0.4f;
	bool engageReverseGeneration = false;
	float chunkXLength = 0;
	float section1Length = 0;
	float section2Length = 0;
	float section3Length = 0;
	float gapLength = 0;
	float previousChunkLength = 0;
	float startOffset=-825.f; //the starting position of the otter offset to fgPhysics.px
	float gapClosure = -180.f; //used in death calculation to narrow hitbox
	int gapLocation = 0; //designates the location of a gap to 1 or 2

	//Platform Generation
	Platform* platforms;
	int platformCounter = 0;// records the amount of platforms generated
	void updatePlatforms(bool left, bool right, float otterSpeed);
	void renderPlatforms(sf::RenderWindow* window);
	//
	Foliage foli; // class of foliage data
	
public:
	Chunk();
	void setPlatformAmount(int x);
	void initChunk(int a, int b, int c, float d, float e);
	void initPlatform(int platformNumber, float x, float y, int l);
	void updateChunk(bool left, bool right, float otterSpeed, bool dontScroll);
	void renderChunk(sf::RenderWindow* window);
	void renderChunkFoliage(sf::RenderWindow* window);
	void renderChunkTree(sf::RenderWindow* window);
	float returnChunkXLength();
	float returnChunkXPos();
	float returnStartOffset();
	float returnScaleFactor();
	float returnPlatfromCounter();
	float returnPlatformXDemension(int platformNumber);
	float returnPlatformYDemension(int platformNumber);
	float returnPlatformXPosition(int platformNumber);
	float returnPlatformYPosition(int platformNumber);
	bool death();
	~Chunk();
};

/*
int a,b,c - integers corrosponding, In order, to the 3 foreground terrain blocks generated. 
	level 1 - 0 main platform, 1 left platform, 3 right platform, 4 water plat form

float d - flating value of the gap inbetween "gap" platforms (in no gap platforms set to 0.f)

float e - starting x value for the next chunk



Chunk(int a,int b, int c, float d)


int x/y - sets the location of the top left first platform
int l - sets the length of the platform in blocks
chunk.setPlatform(int x, int y, int l)




*/