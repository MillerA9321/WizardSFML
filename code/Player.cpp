#include "Player.h"

Player::Player()
{
	playerSpeedPps = START_SPEED;
	playerMaxHealth = START_HEALTH;
	playerCurrentHealth = START_HEALTH;

	playerTexture.loadFromFile("sprites/wizard.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.5, 0.5);
	playerSprite.setOrigin(128, 128);
}

void Player::spawnPlayer(IntRect arena, Vector2f resolution, int tileSize)
{
	// Place the player in the middle of the arena
	playerPosition.x = arena.width / 2;
	playerPosition.y = arena.height / 2;

	// Copy the details of the arena to the player's m_Arena
	arenaSize.left = arena.left;
	arenaSize.width = arena.width;
	arenaSize.top = arena.top;
	arenaSize.height = arena.height;

	// Remember how big the tiles are in this arena
	arenaTileSize = tileSize;

	// Strore the resolution for future use
	screenResolution.x = resolution.x;
	screenResolution.y = resolution.y;

}

Time Player::getLastHitTime()
{
	return playerLastHit;
}

bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - playerLastHit.asMilliseconds() > 200)// 2 tenths of second
	{
		playerLastHit = timeHit;
		playerCurrentHealth-= 10;
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

float Player::getRotation()
{
	return playerSprite.getRotation();
}

Sprite Player::getPlayerSprite()
{
	return playerSprite;
}

int Player::currentHealth()
{
	return playerCurrentHealth;
}

void Player::moveLeft()
{
	keyLeftPressed = true;
}

void Player::moveRight()
{
	keyRightPressed = true;
}

void Player::moveUp()
{
	keyUpPressed = true;
}

void Player::moveDown()
{
	keyDownPressed = true;
}

void Player::stopLeft()
{
	keyLeftPressed = false;
}

void Player::stopRight()
{
	keyRightPressed = false;
}

void Player::stopUp()
{
	keyUpPressed = false;
}

void Player::stopDown()
{
	keyDownPressed = false;
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

	if (keyRightPressed)
	{
		playerPosition.x += playerSpeedPps * elapsedTime;
	}

	if (keyLeftPressed)
	{
		playerPosition.x -= playerSpeedPps * elapsedTime;
	}

	playerSprite.setPosition(playerPosition);



	// Player bounding
	if (playerPosition.x > arenaSize.width - arenaTileSize)
	{
		playerPosition.x = arenaSize.width - arenaTileSize;
	}

	if (playerPosition.x < arenaSize.left + arenaTileSize)
	{
		playerPosition.x = arenaSize.left + arenaTileSize;
	}

	if (playerPosition.y > arenaSize.height - arenaTileSize)
	{
		playerPosition.y = arenaSize.height - arenaTileSize;
	}

	if (playerPosition.y < arenaSize.top + arenaTileSize)
	{
		playerPosition.y = arenaSize.top + arenaTileSize;
	}

	// Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - screenResolution.y / 2,
		mousePosition.x - screenResolution.x / 2)
		* 180) / 3.141;

	playerSprite.setRotation(angle);
}

Vector2f Player::getPlayerCoordinates()
{
	return playerPosition;
}

/**
void Player::upgradeSpeed()
{
	m_Speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	m_MaxHealth += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int amount)
{
	playerCurrentHealth += amount;

	if (playerCurrentHealth > playerMaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

**/