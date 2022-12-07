#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 100;
	const float START_HEALTH = 1000;

	// Player Position
	Vector2f playerPosition;

	Sprite playerSprite;

	Texture playerTexture;

	Vector2f screenResolution;

	IntRect arenaSize;

	int arenaTileSize;

	// Getting the direction of player movement
	bool keyUpPressed;
	bool keyDownPressed;
	bool keyLeftPressed;
	bool keyRightPressed;

	// Current Health
	int playerCurrentHealth;
	// Player max Health
	int playerMaxHealth;

	// Player last hit
	Time playerLastHit;

	// Speed in pixels per second
	float playerSpeedPps;

public:

	Player();
	void spawnPlayer(IntRect arena, Vector2f resolution, int tileSize);
	bool hit(Time timehit);
	Time getLastHitTime();
	FloatRect getPlayerPosition();
	Vector2f getPlayerCenter();
	float getRotation();
	Sprite getPlayerSprite();

	int currentHealth();

	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();

	void stopLeft();
	void stopRight();
	void stopDown();
	void stopUp();

	void updatePlayer(float elapsedTime, Vector2i mousePosition);

};



