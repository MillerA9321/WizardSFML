#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Entity::Entity()
{
    maxHealth = 100;
    damageDealt = 10;
    maxSpeed = 20;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/greenSlime.png"));
    slimeSprite.setScale(1, 1);
    slimeSprite.setOrigin(16, 16);
}

void Entity::hit()
{
    currentHealth -= 50;
}

bool Entity::isAlive()
{
    if (currentHealth > 0)
    {
        return false;
    }
    else
    {
        return true;
    } 
}

Sprite Entity::getSprite()
{
    return slimeSprite;
}


FloatRect Entity::getPosition()
{
    return slimeSprite.getGlobalBounds();
}

void Entity::updatePosition(float elapsedTime,
	Vector2f playerLocation)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;

	// Update the zombie position variables
	if (playerX > slimePosition.x)
	{
		slimePosition.x = slimePosition.x +
			maxSpeed * elapsedTime;
	}

	if (playerY > slimePosition.y)
	{
		slimePosition.y = slimePosition.y +
			maxSpeed * elapsedTime;
	}

	if (playerX < slimePosition.x)
	{
		slimePosition.x = slimePosition.x -
			maxSpeed * elapsedTime;
	}

	if (playerY < slimePosition.y)
	{
		slimePosition.y = slimePosition.y -
			maxSpeed * elapsedTime;
	}

	// Move the sprite
	slimeSprite.setPosition(slimePosition);

	// Face the sprite in the correct directionvvvvvvvvv
	

}



void Entity::slimeSpawn(float x, float y, string slimeType)
{
    if(slimeType == "King")
    {
        KingSlime slimeKing;
        slimeSprite = slimeKing.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if(slimeType == "Red")
    {
        RedSlime redSlime;
        slimeSprite = redSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if(slimeType == "Yellow")
    {
        YellowSlime yellowSlime;
        slimeSprite = yellowSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if (slimeType == "Green")
    {
        GreenSlime greenSlime;
        slimeSprite = greenSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }
}



