#include "Player.h"
Player::Player()
{
	playerSpeedPps = PLAYERSTARTSPEED;
	playerCurrentHealth = PLAYERSTARTHEALTH;
	playerMaxHealth = PLAYERSTARTHEALTH;

	playerTexture.loadFromFile("sprites/player1.png");
	playerSprite.setTexture(playerTexture);

	playerSprite.setOrigin(25, 25);
}

void Player::playerSpawn(IntRect arena, Vector2f resolution, int tileSize)
{
	// Spawn in the middle of the map
	playerPosition.x = arena.width / 2;
	playerPosition.y = arena.width / 2;

	// Copy arena to the players arena
	arenaSize.left = arena.left;
	arenaSize.width = arena.width;
	arenaSize.top = arena.top;
	arenaSize.height = arena.height;

	arenaTileSize = tileSize;

	screenResolution.x = resolution.x;
	screenResolution.y = resolution.y;
}

void Player::resetPlayerStats()
{
	playerSpeedPps = PLAYERSTARTSPEED;
	playerCurrentHealth = PLAYERSTARTHEALTH;
	playerMaxHealth = PLAYERSTARTHEALTH;
}

Time Player::getLastHitTime()
{
	return playerLastHit;
}

bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() > 200)
	{
		playerLastHit = timeHit;
		playerCurrentHealth -= 10;
		
		return true;
	}
	else
	{
		return false;
	}
}

FloatRect Player::getPlayerPosition()
{
	return playerSprite.getGlobalBounds();
}

Vector2f Player::getPlayerCenter()
{
	return playerPosition;
}

float Player::getPlayerRotation()
{
	return playerSprite.getRotation();
}

Sprite Player::getPlayerSprite()
{
	return playerSprite;
}

int Player::getHealth()
{
	return playerCurrentHealth;
}

void Player::moveUp()
{
	keyUpPressed = true;
}

void Player::moveDown()
{
	keyDownPressed = true;
}

void Player::moveLeft()
{
	keyLeftPressed = true;
}

void Player::moveRight()
{
	keyRightPressed = true;
}

void Player::stopUp()
{
	keyUpPressed = false;
}

void Player::stopDown()
{
	keyDownPressed = false;
}

void Player::stopLeft()
{
	keyLeftPressed = false;
}

void Player::stopRight()
{
	keyRightPressed = false;
}

void Player::updatePlayer(float elapsedTime, Vector2i mousePosition)
{
	if (keyUpPressed)
	{
		playerPosition.y -= playerSpeedPps * elapsedTime;
	}

	if (keyDownPressed)
	{
		playerPosition.y += playerSpeedPps * elapsedTime;
	}

	if (keyLeftPressed)
	{
		playerPosition.x -= playerSpeedPps * elapsedTime;
	}

	if (keyRightPressed)
	{
		playerPosition.x += playerSpeedPps * elapsedTime;
	}
	// Player Bounding
	if (playerPosition.y > arenaSize.width - arenaTileSize)
	{
		playerPosition.y = arenaSize.width - arenaTileSize;
	}

	if (playerPosition.y < arenaSize.width + arenaTileSize)
	{
		playerPosition.y = arenaSize.width + arenaTileSize;
	}

	if (playerPosition.x > arenaSize.width - arenaTileSize)
	{
		playerPosition.x = arenaSize.width - arenaTileSize;
	}

	if (playerPosition.x < arenaSize.width + arenaTileSize)
	{
		playerPosition.x = arenaSize.width + arenaTileSize;
	}
	// Player Angle
	float angle = (atan2(mousePosition.y - screenResolution.y / 2, mousePosition.x - screenResolution.x / 2) * 180) / 3.141;
	playerSprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
	playerSpeedPps += (PLAYERSTARTSPEED * 2);
}

void Player::upgradeHealth()
{
	playerMaxHealth += (PLAYERSTARTHEALTH * .2);
}

void Player::increaseHealthLevel(int amount)
{
	playerCurrentHealth += amount;

	if (playerCurrentHealth > playerMaxHealth)
	{
		playerCurrentHealth = playerMaxHealth;
	}
}