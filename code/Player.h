#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
public:
	Player();
	void playerSpawn(IntRect arena, Vector2f resolution, int tileSize);
	void resetPlayerStats();

	bool hit(Time timeHit);

	Time getLastHitTime();

	FloatRect getPlayerPosition();

	Vector2f getPlayerCenter();

	float getPlayerRotation();

	Sprite getPlayerSprite();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();

	void updatePlayer(float elapsedTime, Vector2i mousePosition);
	void upgradeSpeed();
	void upgradeHealth();
	void increaseHealthLevel(int amount);

	int getHealth();

private:
	const float PLAYERSTARTSPEED = 200;
	const float PLAYERSTARTHEALTH = 100;

	Vector2f playerPosition;

	Sprite playerSprite;

	Texture playerTexture;

	Vector2f screenResolution;

	IntRect arenaSize;

	int arenaTileSize;

	bool keyUpPressed;
	bool keyDownPressed;
	bool keyLeftPressed;
	bool keyRightPressed;

	int playerCurrentHealth;
	int playerMaxHealth;

	Time playerLastHit;

	// playerSpeed in Pixels Per Second (pps)
	float playerSpeedPps;
};